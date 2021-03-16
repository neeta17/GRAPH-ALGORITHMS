#include <stdio.h>
#include<time.h>
struct tnode
{
    int data;
    struct tnode *right;
    struct tnode *left;
};


struct tnode *CreateBST(struct tnode *root, int item)
{
    if(root == NULL)
    {
        root = (struct tnode *)malloc(sizeof(struct tnode));
        root->left = root->right = NULL;
        root->data = item;
        return root;
    }
    else
    {
	if(item < root->data )
            root->left = CreateBST(root->left,item);
         if(item > root->data )
            root->right = CreateBST(root->right,item);
    }
 return(root);
}

void Inorder(struct tnode *root)
{
    if( root != NULL)
    {
        Inorder(root->left);
        printf(" %d ",root->data);
        Inorder(root->right);
    }
}

void Preorder(struct tnode *root)
{
    if( root != NULL)
    {
        printf(" %d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct tnode *root)
{
    if( root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf(" %d ",root->data);
    }
}


struct tnode *seach(struct tnode *root, int key)
{
    if(root == NULL)
    {
        printf("NO nodes in tree\n");
        return;
    }
    else
    {
        if(root->data==key)

            printf("Key found");

        if(key < root->data )
            root->left = seach(root->left,key);
         if(key > root->data )
            root->right = seach(root->right,key);
    }
    return(root);
}


struct tnode *leaf(struct tnode *root)
{
    if(root == NULL)
    {
        printf("NO nodes in tree\n");
        return;
    }
    else
    {
        if(root->left==NULL&&root->right==NULL)
        printf("%d",root->data);
          root->left = leaf(root->left);
         root->right = leaf(root->right);

    }
    return(root);
}

struct tnode * findMin(struct tnode *root)
{
    struct tnode *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
return temp;
}

struct tnode* delete1(struct tnode *root,int data)
{ printf(">>>1\n");
struct tnode *troot=root;
    if(troot==NULL)
    {
        return troot;
        printf(">>>2\n");
    }
    else if (data<troot->data){
        troot->left=delete1(troot->left,data);
         printf(">>>3\n");
     }
    else if (data>troot->data){
        troot->right=delete1(troot->right,data);
         printf(">>>4\n");
        }
    else
    {
        if(troot->left==NULL&&troot->right==NULL)
        {
            free(troot);
            troot=NULL;
            printf(">>>5\n");
            return ;
        }
        else if(troot->left==NULL)
        {
            struct tnode *temp=troot;
            troot=troot->right;
            return troot;
        }
         else if(troot->right==NULL)
        {
            struct tnode *temp=troot;
             troot=troot->left;
            return troot;
        }
        else
        {
            struct tnode *temp=findMin(troot->right);
            troot->data=temp->data;
            printf("temp data %d\n",troot->right->data);
            troot->right=delete1(troot->right,temp->data);
            return troot;
        }
    }
    return root;
}

int main()
{
    struct tnode *root = NULL;
    int choice, item, n, i;
    clock_t start,end;
      time_t t;
    float time_taken;
    do
    {
        printf("\n\nBinary Search Tree Operations\n");
        printf("\n1. Creation of BST");
        printf("\n2. Traverse in Inorder");
        printf("\n3. Traverse in Preorder");
        printf("\n4. Traverse in Postorder");
        printf("\n5. Exit");
        printf("\n6. search\n");
        printf("\n7. delete\n");

        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            //root = NULL;
            srand((unsigned) time(&t));
          //  printf("\n\nBST for How Many Nodes ? ");
         //  scanf("%d",&n);
          //  for(i = 1; i <= n; i++)
          //  {

               printf("\nEnter data for node : ", i);
                scanf("%d",&item);
                //item=rand()%500;
                root = CreateBST(root,item);
         //  }
           // printf("\nBST with %d nodes is ready to Use!!\n", n);
            break;
        case 2:
            printf("\nBST Traversal in INORDER \n");
            Inorder(root);
            break;
        case 3:
            printf("\nBST Traversal in PREORDER \n");
            Preorder(root);
            break;
        case 4:
            printf("\nBST Traversal in POSTORDER \n");
            Postorder(root);
            break;
        case 5:
            printf("\n\n Terminating \n\n");
            break;
        case 6: printf("Enter the element to be searched\n");
                scanf("%d",&item);
                start=clock();

                root=seach(root,item);
                end=clock();

                time_taken=((float)end)/CLOCKS_PER_SEC;
                  printf("\nstart=%f\n",((float)start));
                printf("\nend=%f\n",((float)end));

                printf("dif=%f\n",time_taken);
                 break;
        case 7:printf("Enter the element to be searched\n");
                scanf("%d",&item);
               root= delete1(root,item);
                 break;
        default:
            printf("\n\nInvalid Option !!! Try Again !! \n\n");
            break;
        }
    } while(choice != 5);
    return 0;
}
