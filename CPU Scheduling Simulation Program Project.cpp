#include<bits/stdc++.h>
using namespace std;
/*
    ########################################################################
    #************************ OPERATING SYSTEM LAB ************************#
    #************************ MD. ATIKUZZAMAN SIR  ************************#
    #************************ SAROAR ZAHAN SOJIB **************************#
    #************************ ALHAMDULILLAH AND THANK YOU ALL *************#
    ########################################################################

    #####################################
    ##  SAROAR ZAHAN SOJIB - 171002011 ##
    #####################################
*/

void fileorganization()
{
    string cr,de,se;
    vector<string>so;
    cout<<"Enter the name of Your Directory:";
    string s;
    cin>>s;
    while(true)
    {
        cout<<endl;

        cout<<"1.Create file  "<<"2.Delete file  "<<"3.Search file  "<<endl;
        cout<<"4.Display file  "<<"5.Exit"<<endl;
        cout<<"Enter your Choice:";
        int n;
        cin>>n;
        if(n==5)
        {
            cout<<"Exit Complete"<<endl;
            break;
        }
        switch(n)
        {
            case 1:
                cout<<"Enter the file name:";
                cin>>cr;
                so.push_back(cr);
                break;
            case 2:
                cout<<"Enter the file for Delete:";
                cin>>de;
                for(int i=0;i<so.size();i++)
                {
                    if(so[i]==de)
                        so.pop_back( );
                }
                break;
            case 3:
                cout<<"Enter your file for search:";
                cin>>se;
                for(int i=0;i<so.size();i++)
                {
                    if(so[i]==se)
                    {
                        cout<<se<<" File Found";
                        break;
                    }

                    else
                    {
                        cout<<se<<" File not Fount"<<endl;
                        break;
                    }

                }
                break;
            case 4:
                cout<<"The file is:";
                for(int i=0;i<so.size();i++)
                {
                    cout<<so[i]<<" ";
                }
                cout<<endl;
                break;

        }
    }
}

void bestfit()
{
int fragment[20],b[20],p[20],i,j,nb,np,temp,lowest=9999;
	static int barray[20],parray[20];
	cout<<"Enter the number of blocks:";
	cin>>nb;
cout<<"\nEnter the size of the blocks:-\n";
	for(i=1;i<=nb;i++)
    {
cout<<"Block no."<<i<<":";
cin>>b[i];
    }
cout<<"Enter the number of processes:";
	cin>>np;

	cout<<"\nEnter the size of the processes :-\n";
	for(i=1;i<=np;i++)
    {
cout<<"Process no. "<<i<<":";
cin>>p[i];
    }

	for(i=1;i<=np;i++)
	{
		for(j=1;j<=nb;j++)
		{
			if(barray[j]!=1)
			{
				temp=b[j]-p[i];
				if(temp>=0)
					if(lowest>temp)
					{
						parray[i]=j;
						lowest=temp;
					}
}
		}
fragment[i]=lowest;
		barray[parray[i]]=1;
		lowest=10000;
	}

	cout<<"\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment";
	for(i=1;i<=np &&parray[i]!=0;i++)
		cout<<"\n"<<i<<"\t\t"<<p[i]<<"\t\t"<<parray[i]<<"\t\t"<<b[parray[i]]<<"\t\t"<<fragment[i];
}
void FCPS()
{
            int queue[20],n,head,i,j,k,seek=0,max,diff;
            float avg;
printf("Enter the max range of disk\n");
scanf("%d",&max);
printf("Enter the size of queue request\n");
scanf("%d",&n);
printf("Enter the queue of disk positions to be read\n");
            for(i=1;i<=n;i++)
scanf("%d",&queue[i]);
printf("Enter the initial head position\n");
scanf("%d",&head);
queue[0]=head;
            for(j=0;j<=n-1;j++)
            {
                        diff=(queue[j+1]-queue[j]);
                        seek+=diff;
printf("Disk head moves from %d to %d with seek                                                                                       %d\n",queue[j],queue[j+1],diff);
            }
printf("Total seek time is %d\n",seek);
            avg=seek/(float)n;
printf("Average seek time is %f\n",avg);

}
void MFT()
{
    int n,b,p;
    cout<<"Enter the total memory available (in bytes)-";
    cin>>n;
    cout<<"Enter the block size (in bytes)-";
    cin>>b;
    cout<<"Enter the number of process-";
    cin>>p;
    int ex=n%b;
    int bx=n/b;
    vector<int>so;
    int num,k=1;
    while(p--)
    {
        cout<<"Enter memory required for process "<<k<<" (in bytes)-";
        cin>>num;
        so.push_back(num);
        k++;
    }
    cout<<"Process\tMemory required\tAllocated\tInternal Fragmentation"<<endl;
    int counter=0,s=0;
    vector<int>ne;
    for(int i=0;i<so.size();i++)
    {
        if(s==bx)break;
        else{
            if(so[i]>b)
            cout<<i+1<<"\t\t"<<so[i]<<"\t\t"<<"NO"<<"\t\t"<<"----";
        else
        {
            cout<<i+1<<"\t\t"<<so[i]<<"\t\t"<<"YES"<<"\t\t"<<b-so[i];
            counter=counter+(b-so[i]);
            ne.push_back(b-so[i]);
               s++;
        }
        }
        cout<<endl;
    }
    //cout<<s<<endl;
    cout<<"Memory is Full,Remaining processes cannot be accommodated"<<endl;
    cout<<"Total Internal Fragmentation is :"<<counter<<endl;
    cout<<"Total External Fragmentation is :"<<ex<<endl;


}
void bankers()
{
    int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10];
    int p, r, i, j, process, count;
    count = 0;

printf("Enter the no of processes : ");
scanf("%d", &p);

for(i = 0; i< p; i++)
        completed[i] = 0;

printf("\n\nEnter the no of resources : ");
scanf("%d", &r);

printf("\n\nEnter the Max Matrix for each process : ");
for(i = 0; i< p; i++)
    {
printf("\nFor process %d : ", i + 1);
for(j = 0; j < r; j++)
scanf("%d", &Max[i][j]);
             }

printf("\n\nEnter the allocation for each process : ");
for(i = 0; i< p; i++)
    {
printf("\nFor process %d : ",i + 1);
for(j = 0; j < r; j++)
scanf("%d", &alloc[i][j]);
    }

printf("\n\nEnter the Available Resources : ");
for(i = 0; i< r; i++)
scanf("%d", &avail[i]);

for(i = 0; i< p; i++)

for(j = 0; j < r; j++)
            need[i][j] = Max[i][j] - alloc[i][j];

        do
        {
printf("\n Max matrix:\tAllocation matrix:\n");

for(i = 0; i< p; i++)
                {
for( j = 0; j < r; j++)
printf("%d ", Max[i][j]);
printf("\t\t");
for( j = 0; j < r; j++)
printf("%d ", alloc[i][j]);
printf("\n");
            }

            process = -1;

for(i = 0; i< p; i++)
            {
                if(completed[i] == 0)//if not completed
                {
                    process = i ;
for(j = 0; j < r; j++)
                    {
                        if(avail[j] < need[i][j])
                        {
                            process = -1;
                            break;
                        }
                    }
                    }
if(process != -1)
                    break;
            }

if(process != -1)
            {
printf("\nProcess %d runs to completion!", process + 1);
safeSequence[count] = process + 1;
                count++;
for(j = 0; j < r; j++)
                {
                    avail[j] += alloc[process][j];
alloc[process][j] = 0;
                    Max[process][j] = 0;
                    completed[process] = 1;
                }
            }
        }
while(count != p && process != -1);

if(count == p)
        {
printf("\nThe system is in a safe state!!\n");
printf("Safe Sequence : < ");
for( i = 0; i< p; i++)
printf("%d ", safeSequence[i]);
printf(">\n");
        }
        else
printf("\nThe system is in an unsafe state!!");

}
void fileallocation()
{
    int n;
    cout<<"Enter your Number: ";
    cin>>n;
    vector<int> a;
        vector<int>b;
        vector<string>so;
    int i=1;

    while(n--)
    {
        int p,q;
        string s;

        cout<<"Enter file name "<<i<<": ";
        cin>>s;
        so.push_back(s);
        cout<<"enter Starting block of file "<<i<<": ";
        cin>>p;
        a.push_back(p);
        cout<<"Enter no of blocks if file "<<i<<": ";
        cin>>q;
        b.push_back(q);
        i++;
    }
    cout<<"File name\tStart Block\tNo of Blocks\t blocks Occupied"<<endl;
    int j;
    for( j=0;j<a.size();j++)
    {
        //if(j==(a.size()-1))break;

        cout<<so[j]<<"\t\t"<<a[j]<<"\t\t"<<b[j]<<"\t\t";
        for(int k=a[j];k<(a[j]+b[j]);k++)
        {
            cout<<k<<" ";
        }
        cout<<endl;
    }


}
void multilevel()
{
   int n,bt[20],wt[20],tat[20],i,j,pt[20],p[20],k,temp;
    float sum=0,avarage,so1,so2;
    n=4;
     cout<<"enter the process: ";
    for(i=0;i<n;i++)
    {
        p[i]=i;
        cin>>pt[i];
    }
    cout<<"enter Burst time: ";
    for(i=0;i<n;i++)
    {
        cin>>bt[i];
    }
    for(i=0;i<n;i++)
for(k=i+1;k<n;k++)
 if(pt[i] > pt[k])
 {
    temp=p[i];
    p[i]=p[k];
    p[k]=temp;
    temp=bt[i];
    bt[i]=bt[k];
    bt[k]=temp;
    temp=pt[i];
    pt[i]=pt[k];
    pt[k]=temp;
 }
    so1 = wt[0] = 0;
    so2 = tat[0] = bt[0];
    for(i=1;i<n;i++)
 {
    wt[i] = wt[i-1] + bt[i-1];
    tat[i] = tat[i-1] + bt[i];
    so1 = so1 + wt[i];
    so2 = so2 + tat[i];
 }

cout<<"\nprocess\t\tsystem \t\tbutst\twaiting";
for(i=0;i<n;i++)
{
   printf("\n%d \t\t %d \t\t%d \t%d",p[i],pt[i],bt[i],wt[i]);

}
cout<<endl;
cout<<"Avarage Time:"<<so1<<endl;
cout<<"Average Turnaround time:"<<so2<<endl;

}

int main()
{
    while(true)
    {
       cout<<"1. File Allocation "<<endl;
    cout<<"2. File Organization "<<endl;
    cout<<"3. MFT "<<endl;
    cout<<"4. Multi level queue Algorithm"<<endl;
    cout<<"5. FCPS "<<endl;
    cout<<"6. Best Fit "<<endl;
    cout<<"7. Bankers Algorithm "<<endl;
    cout<<"8. Exit"<<endl;
    cout<<"Enter your Choice: ";
    int n;
    cin>>n;
    switch(n)
    {
    case 1:
        fileallocation();
        break;
    case 2:
        fileorganization();
        break;
    case 3:
        MFT();
        break;
    case 4:
        multilevel();
        break;
    case 5:
        FCPS();
    case 6:
        bestfit();
        break;
    case 7:
        bankers();
        break;
    case 8:
        cout<<"Thnk You all "<<endl;
        return 0;
        break;

    }
    }


}

