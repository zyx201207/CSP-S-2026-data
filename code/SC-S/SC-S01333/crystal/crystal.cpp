#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
int mx[500010],mxx;
queue<int>qu;
long long b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i==1){
			qu.push(i);
			mx[i]=1;
			b[i]=0;
		}
		else if(a[i]!=a[i-1]){
			b[i]=b[i-1]+mx[i-1]*(a[i]-a[i-1]);
			if(b[i]<=m){
				qu.push(i);
				mx[i]=mx[i-1]+1; 
			}else{
				while(!qu.empty()&&b[i]>m){
					if(b[i]<=m){
						break;
					}
					int q=qu.front();
					qu.pop();
					b[i]-=(a[i]-a[q]);
				}
				qu.push(i);
				mx[i]=qu.size();
			}
		}else{
			mx[i]=mx[i-1]+1;
			b[i]=b[i-1];
			qu.push(i);
		}
		mxx=max(mxx,mx[i]);
//		if(mxx==315186){
//			cout<<i<<"\n";
//			return 0;
//		}
	}
	cout<<mxx;
	return 0;
} 
/*
5 8
-3 -1 2 2 7

*/