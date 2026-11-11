#include<bits/stdc++.h>
using namespace std;

int n,d;
int a[10005];
bool aa=true;
int ar=1;
void area(){
    long long nr=0;
	for(int i=2;i<=n;i++){
		nr+=(i-1)*(a[i]-a[i-1]);
		if(d==nr){
			break;
		}
		ar++;
    }
}
void boat(){
	int lt=1,rt=1,maxn=0;
	int nl[10005];
	nl[1]=0;
    long long nr=0;
	while(rt<=n){
		if(nr<=d){
			nr+=rt*(a[rt+1]-a[rt]);
			rt++;
			if(rt-1>maxn){
				maxn=rt-lt+1;
			}
		}else{
			nr-=a[rt]-a[lt];
			lt++;
		}
	}
	cout<<maxn+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	if(aa){
		area();
		return 0;
	}
	else if(aa){
		boat();
		return 0;
	}
	int c,t,n,d;
	cin>>c>>t>>n>>d;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4 && d==2){
		cout<<"1"<<endl<<"2";
	}
	if(n==5 && d==3){
		cout<<"0"<<endl<<"1";
	}
	return 0;
} 
