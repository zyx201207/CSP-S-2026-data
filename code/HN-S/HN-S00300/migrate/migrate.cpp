#include<bits/stdc++.h>
using namespace std;
int x[2*1000000];
long long n,d;
int sum,s,plussum;
void search(int a,int b,int p,int q){
	if(a==b&&sum==(abs(p-q)/2+1)){
		s++;
		return;
	}
	for(int j=1;;j++){
		if(a+d>=x[a+j]&&a+d<=x[b]){
			sum++;
			search(a+j,b,p,q);
			sum--;
		}
		else break;
	}
}
int add(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			search(i,j,i,j);
			if(s==2){
//				cout<<abs(i-j)/2+1;
//				cout<<i<<' '<<j<<endl;
				plussum++;
			}
			sum=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int i=0;i<n;i++)cin>>x[i];
		for(int i=0;i<=n;i++){
			add();
		}
		cout<<plussum;
		plussum=0,sum=0,s=0;
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}

