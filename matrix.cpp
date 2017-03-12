#include<cstdio>
#include<cstdlib>
#include<cstring>
int n,m,r;
double a[100][100],b[100][100],c[100][100],ans;


void matrix1(int t)
{
		if (a[t][t]!=1.0)
         {
	       for (int i=t+1;i<=n;i++)
              if (a[i][t]==1.0) 
	          {
				  	ans=-ans;
		          double q;
		            for (int j=t;j<=2*n;j++)
		              {
			             q=a[t][j]; a[t][j]=a[i][j]; a[i][j]=q;
		              }
		     /* 	for (int i=1;i<=n;i++)
	             {
			       for (int j=1;j<=2*n;j++)
 		            	if (a[i][j]>=0) printf("%.3lf ",a[i][j]); else  printf("%.2lf ",a[i][j]);
		            printf("\n");
		         }
		         printf("%5.2lf\n",ans);
			     printf("\n");printf("\n"); printf("\n"); */
				 break;
	          }
          }	
        if (a[t][t]==0)
         {
				for (int i=1;i<=n;i++) 
				 if (a[i][t]!=0)
				 {
					double q;
				 	ans=-ans;
		            for (int j=t;j<=2*n;j++)
		              {
			             q=a[t][j]; a[t][j]=a[i][j]; a[i][j]=q;
		              }
		              break;
				 } 
		 }
        if (a[t][t]!=1.0)
	     {
				double m=a[t][t];
					ans*=m;
				for (int j=t;j<=2*n;j++) a[t][j]/=m;
		 } // the first one bacome 1;
   for (int i=t+1;i<=n;i++)
   {
		double m=a[i][t];
	   for (int j=t;j<=2*n;j++)
	   {
		   a[i][j]-=m*a[t][j];
	   }
   }
   
  /* for (int i=1;i<=n;i++)
	    {
			for (int j=1;j<=2*n;j++)
 			if (a[i][j]>=0) printf("%.3lf ",a[i][j]); else  printf("%.2lf ",a[i][j]);
		  printf("\n");
		}
		printf("%5.2lf\n",ans);
		printf("\n");printf("\n");printf("\n");  */
		 
	
    if (t!=n) matrix1(t+1);
}
						
void matrix2(int t)
{
  for(int i=t-1;i>=1;i--)
   {
	double m=a[i][t];
    for (int j=t;j<=2*n;j++)
     {
		a[i][j]-=a[t][j]*m;
	 }
   }
  /*	for (int i=1;i<=n;i++)
	             {
			       for (int j=1;j<=2*n;j++)
 		            	if (a[i][j]>=0) printf("%.3lf ",a[i][j]); else  printf("%.2lf ",a[i][j]);
		             printf("\n");
		         }
			     printf("\n");printf("\n"); printf("\n"); */
   if(t!=1) matrix2(t-1);
}

void plus(int n,int m)
{
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	  c[i][j]=a[i][j]+b[i][j];
}


bool checkzero(int g,int f)
{
	//printf("%d %d",g,f);
	for (int o=g;o<=n;o++)
	 for (int l=f;l<=m;l++)
	  if (a[o][l]!=0) return false;
	return true; 
} 

int matrixrank(int n,int m)
{
  int s=1,e=1;
  while (!checkzero(s,e))
   {
		if (a[s][e]==0) 
		 for (int i=s+1;i<=n;i++) 
		  if (a[i][e]!=0)
		  {
				for (int j=e;j<=m;j++)
				 {
						double q;
						q=a[s][j]; a[s][j]=a[i][j]; a[i][j]=q;
				 }
		  } 
		if (a[s][e]==0)
		 {
				if (e==m) return s;
				else matrixrank(s,e+1);
		 }
		else 
		{
		   if (s<m) matrixrank(s+1,e+1);
		   else return s;
        }
    }
}


int main()
{
	while (true)
  {
    {
		memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        printf("Choose opreations(end with 'enter')\n");
        printf("1:matrix addition\n");
        printf("2:matrix subtraction\n");
        printf("3:matrix multiplication\n"); 
        printf("4:the inverse matrix\n(Notice that the answer maybe unrealiable when the answer contains fractions.)\n");
        //printf("5:DET\n"); 
        //printf("6:the rank of the matrix(STILL TESTING)\n"); 
        printf("enter 'Ctrl+C' to exit\n");
        scanf("%d",&r);
	} 
  switch (r)
  {
  	case 4: //the inverse matrix;
   {
	printf("Enter the order of the matrix:");
	scanf("%d",&n);
	printf("Enter the matrix:\n");
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		scanf("%lf",&a[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=n+1;j<=2*n;j++)
		{
			if ((j-n)==i) 
			 {
					a[i][j]=1.0;
			 }
		}
	matrix1(1);
	matrix2(n);
	printf("The inverse matrix is:\n");
	for (int i=1;i<=n;i++)
	    {
			for (int j=n+1;j<=2*n;j++)
 			  printf("%5.3lf ",a[i][j]);
		  printf("\n");
		}
		break;
    }
    case 3://multiplication
   {
		int v;
		printf("Enter the row and column of the left matrix :");
		scanf("%d%d",&n,&m);
		printf("Enter the column of the right matrix column:");
		scanf("%d",&v);
		printf("Enter the left matrix:\n");
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=m;j++)
		    scanf("%lf",&a[i][j]);
		printf("Enter the right matrix:\n"); 
		for (int i=1;i<=m;i++)
		  for (int j=1;j<=r;j++)
		    scanf("%lf",&b[i][j]);
	//	for (int i=1;i<=m;i++)
	//	 { for (int j=1;j<=r;j++)
	//	    printf("%lf ",b[i][j]);
	//	    printf("\n");
	//	 }
		for (int i=1;i<=n;i++)
		 for (int j=1;j<=r;j++)
		  {
				for (int q=1;q<=m;q++)
				  {
						c[i][j]+=a[i][q]*b[q][j];
						//printf("i=%d j=%d q=%d p=%d c[i][j]=%.lf\n",i,j,q,p,c[i][j]);
				  }
		  }
		for (int i=1;i<=n;i++)
	      {
			for (int j=1;j<=r;j++)
 			  printf("%5.0lf ",c[i][j]);
		    printf("\n");
		  }
	 break;
    }
    case 1: //matrix addition;
	{
		printf("Enter the row and column of the matrixs:");
		scanf("%d%d",&n,&m);
		printf("Enter the left matrix:\n");
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=m;j++)
		    scanf("%lf",&a[i][j]);
		printf("Enter the right matrix:\n"); 
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=m;j++)
		    scanf("%lf",&b[i][j]);
		    plus(n,m);
		for (int i=1;i<=n;i++)
	      {
			for (int j=1;j<=m;j++)
 			  printf("%5.0lf ",c[i][j]);
		    printf("\n");
		  }
		break;
	}
	case 2: //matrix subtraction
	{
		printf("Enter the row and column of the matrixs:");
		scanf("%d%d",&n,&m);
		printf("Enter the left matrix:\n");
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=m;j++)
		    scanf("%lf",&a[i][j]);
		printf("Enter the right matrix:\n"); 
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=m;j++)
		    {
				scanf("%lf",&b[i][j]);
				b[i][j]=-b[i][j];
		    }
		    plus(n,m);
		for (int i=1;i<=n;i++)
	      {
			for (int j=1;j<=m;j++)
 			  printf("%5.0lf ",c[i][j]);
		    printf("\n");
		  }
		break;
	}
	case 5: //DET;
	{ 
		printf("Enter the row and column of the matrixs:");
		scanf("%d",&n);
		ans=1;
		printf("Enter the matrix A:\n");
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=n;j++)
		    scanf("%lf",&a[i][j]);
		matrix1(1);
		for (int i=1;i<=n;i++) ans*=a[i][i]; 
		printf("DET(A)=%.2lf\n",ans);
		break;
	}
    case 6://rank 
	{
		printf("Enter the row and column of the matrixs:");
		int n,m;
		scanf("%d%d",&n,&m);
		//printf("%d%d",n,m);
		printf("Enter the matrix:\n");
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=m;j++)
		   scanf("%lf",&a[i][j]);
		   printf("%d\n",matrixrank(n,m));
    	break;
    }
    	default: printf("Error.\n");
  }
  	system("pause");
  }
  return 0;
}
