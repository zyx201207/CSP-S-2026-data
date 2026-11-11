#include<bits/stdc++.h>
using namespace std;
int a[200010][2];
int num[20]={0},l=0;

void abc(int s){
	int sy=s;
	for(int i=1;sy;i++){
		num[i]+=sy;
		sy=num[i]/10;
		num[i]=num[i]%10;
		l=max(l,i);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n;cin>>n;
	for(char i=0,c;i<n;i++){
		cin>>a[i+1][0]>>c;
		a[i+1][1]=c-'a';
	}
	
	int i=1,j=n;
	while(i<=j){
		if(!a[i][0])i++;
		if(!a[j][0])j--;
		if(a[i][1]!=a[j][1])
			abc(min(a[i][0],a[j][0]));
		a[i][0]-=min(a[i][0],a[j][0]),
		a[j][0]-=min(a[i][0],a[j][0]);
	}
	
	for(int i=l;i>0;i--)cout<<num[i];
	return 0;
}
