
#include<bits/stdc++.h>
using namespace std;
int i,j;
int c1,c2;
string s1[1];
string s2[1];
int q1,q2,q3;
int main(){
	freopen("string.in","r","stdin")
	freopen("string.out","w","stdout")
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


//	j=1;
//	m=0;
//	cin>>l;
//	for(i=0;i<l;i++)
//	{
//		cin>>S1[i]>>S2[i];
//
//	}
//									//S1S2的输入没问题 
//	for(i=0;i<l;i++){
//		cout<<i<<"  "<<y<<"  "<<S1[i]<<"  "<<S1[i] + y<<"  ";
//		y=y+S1[i];
//		cout<<y<<"  ";
//	}
//	cout<<y;
//	for(i=0;i<l;i++){
//		if(S1[i]>0){
//		S1[i]-=S1[i];
//		S0[j]=S2[i];
//			
//		j++;
//		i--;
//		}
//		
//	}
//
//	for(j=1;j<=m;j++)

//	cout<<S0[j];

