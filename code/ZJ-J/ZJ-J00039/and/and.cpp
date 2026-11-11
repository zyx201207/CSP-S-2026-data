#include<bits/stdc++.h>
#define ll long long
// zui hou yi ci le......
using namespace std;
int a[234567];
int c[234567];
int b[36];
vector<int> v[36];
int k;
int n;
ll ans;
int m;
void flbit(int r){
	for(int i=1;i<=r;i++){
		int j=c[i];
		int k1=-1;
		while(j){
			k1++;
			if(j%2){
				b[k1]++;
				v[k1].push_back(c[i]);	
			}
			j/=2;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool fff=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
		if(a[i]!=0)fff=0;
	}if(fff){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	flbit(n);
	/*for(int i=0;i<=32;i++){
		cout<<b[i]<<":";
		for(int j:v[i])cout<<j<<" ";
		cout<<"\n";
	}*/
	bool ff=1;
	for(int i=32;i>=0;i--)if(b[i]>=m){
		k=i;ans+=pow(2,i);ff=0;
		break;
	}if(ff){
		cout<<0;
		return 0;
	}
//	for(int j:v[k])cout<<j<<" ";
//		cout<<"\n";
	while(k>=0){
		memset(c,0,sizeof c);
		memset(b,0,sizeof b);
		int kkksc=0;
		for(int j:v[k])c[++kkksc]=j;
//		for(int j:v[k])cout<<j<<" ";
//		cout<<"\n";
		for(int i=0;i<=34;i++)v[i].clear();
		flbit(kkksc);
		bool f=1;
		k--;if(k<0)break;
		for(int i=k;i>=0;i--)if(b[i]>=m){
			k=i;ans+=pow(2,i);f=0;
			break;
		}if(f){
			cout<<ans;
			return 0;
		}
	}cout<<ans;
	return 0;
} //wc，调了我1h+ 
/*
20 10
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
*/
//我有史以来做题写的第6长的代码 
