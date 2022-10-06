#include<stdio.h>
#include<string.h> // lay compare


//tao struct ngaythangnam
typedef struct NgayThangNam
{
	int ngay;
	int thang;
	int nam;
}Date;
//tao struct nguoi
typedef struct Nguoi
{
	int thehe;
	char hoten[40];
	char ba[40];
	char me[40];
	char vc[40];
	Date ngaysinh;
	int socon;
}N;
//tao node
typedef struct Node
{
	Nguoi data;
	struct Node *next;
}node;
//tao LinkedList
typedef struct LinkedList
{
	Node *head;
	Node *tail;
}LL;
//tao ra 1 node
Node* CreateNode(N data)
{
	Node *newNode = new Node();
	newNode->data= data; 
	newNode->next = NULL;
	return newNode;
}
//kiem tra rong
bool IsEmpty(LinkedList lst)
{
	return (lst.head==NULL && lst.tail==NULL);
}
//tao list
void CreateList(LinkedList &lst)
{
	lst.head = NULL;
	lst.tail = NULL;
}
void XoaNodeDau(LinkedList &lst)
{
	Node *newNode;
	if(IsEmpty(lst))
	{
		printf("\nList Rong !!!");
	}
	else{
		newNode = lst.head;
		lst.head = lst.head->next;
		delete newNode;
	}

}
void XoaGiaPha(LinkedList &lst)
{
	Node *newNode;
	while(lst.head!=NULL)
	{
		newNode = lst.head;
		lst.head = lst.head->next;
		delete newNode;
	}
	printf("\nDa Xoa Gia Pha thanh cong !!");
}
void SapXepTheoTheHe(LinkedList &lst)
{
	Node *newNode1,*newNode2;
	for(newNode1 = lst.head;newNode1->next!=NULL;newNode1=newNode1->next)
	{
		for(newNode2 = newNode1->next; newNode2!=NULL; newNode2 = newNode2->next)
		{
			if(newNode1->data.thehe > newNode2->data.thehe)
			{
				N temp = newNode1->data;
				newNode1->data = newNode2->data;
				newNode2->data = temp;
			}
		}
	}
}
void Xuat1Nguoi(Node *newNode)
{
	printf("%5s|%30s |%30s |%30s |%30s |%10s |%5s","The He","Ho Ten","Ba","Me","Vo/Chong","Nam Sinh","So Con");
	printf("\n%5d |%30s |%30s |%30s |%30s |%2d/%2d/%2d |%5d",newNode->data.thehe,newNode->data.hoten,newNode->data.ba,newNode->data.me,newNode->data.vc,newNode->data.ngaysinh.ngay,newNode->data.ngaysinh.thang,newNode->data.ngaysinh.nam,newNode->data.socon);
}
void XuatGiaPha(LinkedList lst)
{
	if(IsEmpty(lst)==true)
	{
		printf("\nGia Pha Khong Co Ai !!");
	}
	else
	{
		Node *newNode = new Node();
		newNode = lst.head;
		printf("\n---------------------------------------------------------Danh Sach Nguoi Trong Gia Pha-------------------------------------------------------------------\n");
		printf("%5s|%30s |%30s |%30s |%30s |%10s |%5s","The He","Ho Ten","Ba","Me","Vo/Chong","Nam Sinh","So Con");
		while(newNode !=NULL)
		{
			printf("\n%5d |%30s |%30s |%30s |%30s |%2d/%2d/%2d |%5d",newNode->data.thehe,newNode->data.hoten,newNode->data.ba,newNode->data.me,newNode->data.vc,newNode->data.ngaysinh.ngay,newNode->data.ngaysinh.thang,newNode->data.ngaysinh.nam,newNode->data.socon);
			newNode = newNode->next;
		}	
	}
	
}
//dem so nguoi trong gia pha
int count(LinkedList lst)
{
	int dem =0;
	while(lst.head!=NULL)
	{
		++dem;
		lst.head = lst.head->next;
	}
	return dem;
}
// them nguoi vao dau gia pha
void InsertNodeFirst(LinkedList &lst,Nguoi &x)
{
	Node *newNode = CreateNode(x);
	if(IsEmpty(lst)==true)
	{
		lst.head  = newNode;
		lst.tail = newNode;
	}
	else
	{
		newNode->next = lst.head;
		lst.head = newNode;
	}	
}
//them nguoi vao cuoi gia pha
void InsertNodeLast(LinkedList &lst, Nguoi &x)
{
	Node *newNode = CreateNode(x);
	if(IsEmpty(lst))
	{
		lst.head = newNode;
		lst.tail = newNode;
	}else{
		lst.tail->next = newNode;
		lst.tail = newNode;
	}
}





//nhap du lieu cho 1 nguoi
void Nhap1nguoi(N &a)
{	
        printf("\nNhap the he: \n");
        scanf("%d",&a.thehe);
        printf("Nhap ba: \n");
        fflush(stdin);
        gets(a.ba);
		printf("Nhap me: \n");
        fflush(stdin);
        gets(a.me);
		printf("Nhap ho ten: \n");
        fflush(stdin);
        gets(a.hoten);
		printf("Nhap ten vo hoac chong: \n");
        fflush(stdin);
        gets(a.vc);
		printf("Nhap ngay sinh: \n");
        scanf("%d",&a.ngaysinh.ngay);
        printf("Nhap thang sinh: \n");
        scanf("%d",&a.ngaysinh.thang);
        printf("Nhap nam sinh: \n");
        scanf("%d",&a.ngaysinh.nam);
        printf("Nhap so con: \n");
        scanf("%d",&a.socon);
        
}
void GhiFileBin()
{
    FILE *ghi;
    ghi = fopen("dulieu.dat","wb+");

    int n;
	printf("Nhap so luong nguoi trong gia pha: ");
	scanf("%d",&n);
    fwrite(&n,sizeof(n),1,ghi);
	for(int i=0;i<n;i++)
	{
		N x;
		printf("Nhap thong tin Nguoi can them:");
		Nhap1nguoi(x);
        fwrite(&x,sizeof(N),1,ghi);
		//InsertNodeFirst(lst,x);
	}

    fclose(ghi);
}

//nhap du lieu cho gia pha
void DocDuLlieu(LinkedList &lst)
{
    FILE *doc;
    doc = fopen("dulieu.dat","rb");
	int n;
    fread(&n,sizeof(n),1,doc);
	for(int i=0;i<n;i++)
	{
		N x;

		printf("Nhap thong tin Nguoi can them:");
		// Nhap1nguoi(x);
        fread(&x,sizeof(N),1,doc);
		InsertNodeLast(lst,x);

		//InsertNodeFirst(lst,x);
	}
    fclose(doc);
}

//kiem tra nguoi do co trong gia pha khong
int Kiemtra(LinkedList &lst,int t,char ten[])
{
	if(IsEmpty(lst)==true)
	{
		return -1;
	}
	else
	{
		Node *newNode = new Node();
		newNode = lst.head;
		while(newNode !=NULL)
		{
			if(strcmp(newNode->data.hoten,ten)==0 && newNode->data.ngaysinh.nam==t)
			{
				return 1;
			}
			newNode = newNode->next;
		}	
		return -1;
	}
}
//xuat nhung nguoi cung the he va con chau cua nguoi do
void XuatConChauTH(LinkedList &lst,int t)
{
	if(IsEmpty(lst)==true)
	{
		return;
	}
	else
	{
		Node *newNode = new Node();
		newNode = lst.head;
		printf("\n---------------------------------------------------------Danh Sach Nguoi Trong Gia Pha-------------------------------------------------------------------\n");
		printf("%5s|%30s |%30s |%30s |%30s |%10s |%5s","The He","Ho Ten","Ba","Me","Vo/Chong","Nam Sinh","So Con");
		while(newNode !=NULL)
		{
			if(newNode->data.thehe>=t)
			printf("\n%5d |%30s |%30s |%30s |%30s |%2d/%2d/%2d |%5d",newNode->data.thehe,newNode->data.hoten,newNode->data.ba,newNode->data.me,newNode->data.vc,newNode->data.ngaysinh.ngay,newNode->data.ngaysinh.thang,newNode->data.ngaysinh.nam,newNode->data.socon);
			newNode = newNode->next;
		}	
	}
}


//tim vi tri cua 1 nguoi trong gia pha
int VitriCuaNguoi(LinkedList lst,Node *NodeTim)
{
	Node *newNode= lst.head;
	int vt=0;
	while(newNode !=NodeTim && newNode!=NULL)
	{
		newNode = newNode->next;
		vt++;
	}
	if(newNode==NULL)	return -1;
	return vt;
}
//tim nguoi o 1 vi tri nao do
Node* TraNguoiOViTri(LinkedList lst,int i)
{
	Node *newNode = lst.head;
	int vt=0;
	while(newNode!=NULL && vt!=i)
	{
		newNode= newNode->next;
		vt++;
	}
	return newNode;
}

void InsertNodeMid(LinkedList &lst, int pos, N d){
  if(pos < 0 || pos >= count(lst)){
    printf("\nKhong the chen");
    return;
  }
  if(pos == 0){
    InsertNodeFirst(lst, d);
  }
  else if(pos == count(lst)-1){
    InsertNodeLast(lst, d);
  }
  else{
    Node *newNode = CreateNode(d);
    Node *current = lst.head;
    Node *pre = NULL;
    int i = 0;
    while(current != NULL){
      if(i == pos)
      	break;
      pre = current;
      current = current->next;
      i++;
    }
    pre->next=newNode;
    newNode->next=current;
  }
}

int main()
{
	LinkedList lst;
	CreateList(lst);
   // GhiFileBin();
	DocDuLlieu(lst);
	int select;
	do
	{
		printf("\n1 - Xuat Gia Pha\n2 - Tim nguoi trong gia pha\n3 - Xuat ra con chau va nguoi cung the he\n4 - Xoa Gia Pha");
		printf("\n5 - Sap Xep Gia Pha theo the he\n6 - Xuat Nguoi o 1 vi tri trong gia pha\n7 - Xoa Nguoi Dau Gia Pha\n8 - Them Nguoi vao cuoi Gia Pha");
		printf("\n9 - Them Nguoi Giua Gia Pha\n10 - Luu file \n11 - Dem so nguoi trong gia pha\n0 - Thoat");
		printf("\nMoi ban chon chuc nang: ");
		scanf("%d",&select);
		switch (select)
    	{
    		case 1:
        		XuatGiaPha(lst);
       			break;
   			case 2:
				char x[40];
				printf("\nNhap vao ten 1 nguoi: ");
				fflush(stdin);
				gets(x);
				int namsinh;
				printf("\nNhap nam sinh: ");
				scanf("%d",&namsinh);
        		if(Kiemtra(lst,namsinh,x)!=-1)
					printf("\nCo %s trong gia pha",x);
				else	
				printf("\nkhong Co %s trong gia pha",x);
        		break;
   			 case 3:
        		char d[40];
				printf("\nNhap vao ten 1 nguoi: ");
				fflush(stdin);
				gets(d);
				int n;
				printf("\nNhap nam sinh: ");
				scanf("%d",&n);
				int th;
				printf("\nNhap vao the he: ");
				scanf("%d",&th);
				if(Kiemtra(lst,n,d) == -1)
					printf("\nKhong co nguoi ay trong gia pha !");
				else
				{
					XuatConChauTH(lst,th);
				}	
        		break;
			case 4:
				XoaGiaPha(lst);
				break;
			case 5:
				SapXepTheoTheHe(lst);
				printf("\n------------Gia Pha Sau khi sap xep theo the he------------\n");
				XuatGiaPha(lst);
				break;
			case 6:
				int vt;
				printf("\nVui long nhap vi tri(0 -> songuoi-1): ");
				scanf("%d",&vt);
				Xuat1Nguoi(TraNguoiOViTri(lst,vt));
				break;
			case 7:
				XoaNodeDau(lst);
				printf("\n------------Gia Pha Sau khi Xoa------------\n");
				XuatGiaPha(lst);
				break;
			case 8:
				N t;
				printf("Nhap thong tin Nguoi can them:");
				Nhap1nguoi(t);
				InsertNodeLast(lst,t);
				printf("\nThem thanh cong !!");
				break;
			case 9:
				N u;
				printf("Nhap thong tin Nguoi can them:");
				Nhap1nguoi(u);
				int pos;
				printf("\nVui long nhap vi tri(0 -> songuoi-1): ");
				scanf("%d",&pos);
				InsertNodeMid(lst,pos,u);
				break;
			case 10:
				
			case 11:
				printf("\nSo luong nguoi trong Gia Pha: %d",count(lst));
				break;

   		 }
    fflush(stdin);
	} while (select!=0);	
	return 0;	
}