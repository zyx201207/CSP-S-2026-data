#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,l;
char S1[100000];
char S2[100000];
char S0[100000];
int main(){
    freopen("and.in","r","stdin")	
	freopen("and.out","w","stdout")		
	j=1;
	cin>>l;
	for(i=0;i<l;i++)
	{
		cin>>S1[i]>>S2[i];

	}
									//S1S2的输入没问题 
	for(i=0;i<l;i++){
		if(S1[i]>0){
		S1[i]=S1[i]-1;
		S0[j]=S2[i];
		j++;
		i--;}
		
	}
	for(i=0;i<l;i++){
		m+=S1[i];
	}
	for(j;j<=m;j++)
	if(S0[j]!=S0[m+1-j]){
	k++;}
	cout<<k;
}

