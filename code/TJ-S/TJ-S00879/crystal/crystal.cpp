#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a,b,c[200010],d=0,ee=0;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	if(a<100){
		sort(c+1,c+a+1);
		long long e=0;
		for(int i=1;i<=a;i++){
			e+=i*(c[i+1]-c[i]);
			ee=i;
			if(b<=e){
				break;
			}
			
		}
		cout<<ee+1;	
		
	}else{
		d=abs(c[1]-c[2]);
		long long e=0;
		for(int i=1;b>=e;i++){
			e+=i*d;
			if(b<e){
				break;
			}
			ee=i;
		
		}
		cout<<ee+1;	
	}
	
	return 0;
}
