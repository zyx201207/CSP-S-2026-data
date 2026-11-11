#include<bits/stdc++.h>
using namespace std;
	long long q,w,e[500001],r=10000000000000,t=-10000000000000,h=0;
	
		bool cmp(long long a,long long b){
			return a>b;
		}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>q>>w;
	for(int i=1;i<=q;i++){
		cin>>e[i];
		if(r>e[i]){
		r=e[i];
		}
		if(t<e[i]){
		t=e[i];
		}
	}
	sort(e+1,e+q+1);
		for(int i=r;i<=t;i++){
		long long b=w;	
			long long x=0;
			for(int j=1;j<=q;j++){
				if(e[j]<=i&&b>0&&b>=(i-e[j])){
					b-=b-(i-e[j]);
				
					x++;
				}else{
					continue;
				}
			}
			if(x>h){
				h=x;
			}
		}
	cout<<h;
}
