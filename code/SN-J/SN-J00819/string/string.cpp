#include<bits/stdc++.h>
using namespace std;
struct s{
	long long a;
	char c;
};
s d[200001];
s e[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=0,di=1,ei=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i].a>>d[i].c;
		e[n-i+1].a=d[i].a;
		e[n-i+1].c=d[i].c;
	}
	
	while(di<=n&&ei<=n){
		if(d[di].a>e[ei].a){
//			cout<<"1"<<endl;cout<<di<<":"<<d[di].a<<" "<<ei<<":"<<e[ei].a<<endl;
			if(d[di].c!=e[ei].c){
				num+=e[ei].a;
			}
			d[di].a-=e[ei].a;
			e[ei].a=0;
			ei++;
		}else if(d[di].a<e[ei].a){
//			cout<<"2"<<endl;cout<<di<<":"<<d[di].a<<" "<<ei<<":"<<e[ei].a<<endl;
			if(d[di].c!=e[ei].c){
				num+=d[di].a;
			}
			e[ei].a-=d[di].a;
			d[di].a=0;
			di++;
		}else{
//			cout<<"3"<<endl;cout<<di<<":"<<d[di].a<<" "<<ei<<":"<<e[ei].a<<endl;
			if(d[di].c!=e[ei].c){
				num+=d[di].a;
			}
			d[di].a=0;
			e[ei].a=0;
			di++;
			ei++;
		}
		
	}cout<<num/2;
}
