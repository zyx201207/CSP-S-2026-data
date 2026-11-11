#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	long long int b;
	bool h[30]={};
}a[200099];
long long int w[30],t,s;
bool cmp(node u,node v){
	for(int i=29;i>=0;i--)if(u.h[i]!=v.h[i])return u.h[i]>v.h[i];
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<30;i++){
		w[i]=1<<i;
		//cout<<w[i]<<endl;
	}
	//cout<<"OK\n";
	for(int i=1;i<=n;i++){
		int j=29;
		cin>>t;
		a[i].b=t;
		//cout<<i<<" "<<a[i].b<<"\n";
		while(t>0){
			//cout<<t<<"\n";
			if(w[j]<=t){
				t-=w[j];
				a[i].h[j]=1;
			}else j--;
		}
	}
	//cout<<"OK\n";
	sort(a+1,a+1+n,cmp);
	s=a[1].b;
	for(int i=2;i<=m;i++)s&=a[i].b;
	cout<<s;
	return 0;
}
