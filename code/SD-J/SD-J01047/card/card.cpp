#include<bits/stdc++.h>
using namespace std;string y="";int n,m,a[500005],num[500005];
int appl(int a,string b,int c){
	for(int i=0;i<=a;i++){
		if(b[i]==c+'0')return 1;
	}
}
void xy(int t){
	 y+=a[t]+'0';
	for(int i=t+1;i<n;i++){
		if(appl(i,y,a[i]))y.clear();
		y+=a[i]+'0';
	}
	for(int i=0;i<y.size();i++){
		num[y[i]-'0']++;
	}
	y.clear();
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int t=0;t<n;t++){
		xy(t);
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
