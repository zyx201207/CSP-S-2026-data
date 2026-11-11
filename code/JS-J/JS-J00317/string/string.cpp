#include<iostream>
using namespace std;
struct node{
	long name;
	long s;
	char c;
}a[2000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
		a[i].name=i;
	}
	node nu=a[1];
	node nd=a[n];
	long long ans=0;
	while(nu.name<=nd.name){
		if(nu.c==nd.c){
			if(nu.s>=nd.s){
				nu.s-=nd.s;
				nd.s=0;
			}else{
				nd.s-=nu.s;
				nu.s=0;
			}
		}else{
			if(nu.s>=nd.s){
				nu.s-=nd.s;
				ans+=nd.s;
				nd.s=0;
			}else{
				nd.s-=nu.s;
				ans+=nu.s;
				nu.s=0;
			}
		}
		//cout<<"run:nu{"<<nu.name<<","<<nu.s<<","<<nu.c<<"}nd{"<<nd.name<<","<<nd.s<<","<<nd.c<<"}\n";
		if(nu.s<=0){
			//cout<<"nu\n";
			nu=a[++nu.name];
		}
		if(nd.s<=0){
			//cout<<"nd\n";
			nd=a[--nd.name];
		}
		//cout<<"run:nu{"<<nu.name<<","<<nu.s<<","<<nu.c<<"}nd{"<<nd.name<<","<<nd.s<<","<<nd.c<<"}\n";
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
