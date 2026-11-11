#include<bits/stdc++.h>
using namespace std;
long long c,t,q[100001];
bool d=1;
struct z{
	
}aaa[100001];
int main(){
	freopen(migrate.in,"r",stdin);
	freopen(migrate.out,"w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		long long n,d,a[100001],b=0;
		cin>>n>>d;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				d=1;
				int t=0;
				for(int k=i,k<=j;k++){
					if(a[k+1]-a[k]<=d);
					else {
						d=0;
						break;
					}
				}
				if(d&&t==2)b++;
			}
		}
		q[i]=b;
	}
	for(int i=0;i<t;i++)cout<<q[i]<<endl;
}