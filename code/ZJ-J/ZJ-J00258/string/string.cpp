#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e5+10;
struct node{
	ll num;
	char c;
}b[N];
ll a[N],cnt;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(c[i]==c[i-1]){
			b[cnt].num=b[cnt].num+a[i];
		}else{
			cnt++;
			b[cnt].num=a[i];
			b[cnt].c=c[i];
		}
	}
//	for(int i=1;i<=cnt;i++){
//		cout<<b[i].num<<" "<<b[i].c<<endl;
//	}
	ll l=1,r=cnt,ans=0;
	while(l<r){
		//cout<<b[l].num<<" "<<b[r].num<<endl;
		if(b[l].c==b[r].c){
			ll k=min(b[l].num,b[r].num);
			b[l].num-=k;
			b[r].num-=k;
			if(b[l].num==0) l++;
			if(b[r].num==0) r--;
		}else{
			//cout<<"!";
			ll k=min(b[l].num,b[r].num);
			//cout<<k<<" ";
			ans+=k;
			b[l].num-=k;
			b[r].num-=k;
			if(b[l].num==0) l++;
			if(b[r].num==0) r--;
		}
	}cout<<ans;
	return 0;
}

