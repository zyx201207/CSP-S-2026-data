#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n;
struct CH{
	int l,r,len;
	char c;
}a[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int pos=0,cnt=0;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		a[++cnt]={pos+1,pos+x,x,c};
	}
	int pl=1,pr=a[cnt].r;
	int i=1,j=cnt;
	long long ans=0;
	while(i<j){
		if(a[i].len<a[j].len){
			if(a[i].c!=a[j].c)ans+=a[i].len;
			a[j].len-=a[i].len;
			pl+=a[i].len,pr-=a[i].len;
			i++;
		}else if(a[i].len>a[j].len){
			if(a[i].c!=a[j].c)ans+=a[j].len;
			a[i].len-=a[j].len;
			pl+=a[j].len,pr-=a[j].len;
			j--;
		}else{
			if(a[i].c!=a[j].c)ans+=a[i].len;
			i++,j--;
			pl+=a[i].len,pr-=a[i].len;
		}
	}
	cout<<ans;
	return 0;
}
