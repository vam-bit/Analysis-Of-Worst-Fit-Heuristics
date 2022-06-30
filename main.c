#include<stdio.h>
#include<conio.h>
#define max 25
void main()
{ int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0; static int bf[max],ff[max]; printf("\n\tAlmost Worst Fit"); printf("\nEnter the number of blocks :");
scanf("%d",&nb);
printf("Enter the number of files :"); scanf("%d",&nf); printf("\nEnter the size of the blocks:\n"); for(i=1;i<=nb;i++)
{ printf("Block %d:",i); scanf("%d",&b[i]);
}
printf("\nEnter the size of the files:-\n");
for(i=1;i<=nf;i++)
{ printf("File%d:",i); scanf("%d",&f[i]);
} for(i=1;i<=nb;++i) { for(j=i+1;j<=nb;++j)
{ if(b[i]<b[j]){ int a=b[i]; b[i]=b[j]; b[j]=a;
}
} } for(i=1;i<=nf;i++)
{ for(j=2;j<=nb;j++)
{ if(bf[j]!=1)
{ temp=b[j]-f[i]; if(temp>=0){
ff[i]=j;
highest=temp;
frag[i]=highest; bf[ff[i]]=1; highest=0; break; } else{ if(bf[1]!=1){ if((b[1]-f[i]>0)){ ff[i]=1; highest=(b[1]-f[i]); bf[1]=1; frag[i]=highest; bf[ff[i]]=1; highest=0; break;
}
}
}
}
} } printf("\nFile_no:\tFile_size:\tBlock_size:\tFragment")
; for(i=1;i<=nf;i++) printf("\n%d\t\t%d\t\t%d\t\t%d",i,f[i],b[ff[i]],frag[i]);
getch();
}
