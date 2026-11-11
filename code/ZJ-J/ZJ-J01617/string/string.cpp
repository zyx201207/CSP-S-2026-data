#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int N=2e5+5;
struct node{
	int len;
	char c;
}a[N],b[N],P[N];
string SS;
int s,sum,l[N],ans;
char c[N];
int n,c1,c2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>c[i],sum+=l[i];
	}
	int S=sum/2;bool f=0;
	for(int i=1;i<=n;i++){
		s+=l[i];char C=c[i];
		if(s>=S&&!f){
			int l1=S-(s-l[i]),l2=l[i]-l1-(sum%2);
			if(l1>0) a[++c1]={l1,C};
			if(l2>0) b[++c2]={l2,C};
			f=1;
		}else{
			if(f==0) a[++c1]={l[i],C};
			else b[++c2]={l[i],C};
		}
	}
	for(int i=1;i<=c2;i++) P[i]=b[i];
	for(int i=1;i<=c2;i++) b[i]=P[c2-i+1];
	int i=0,j=0,x=0,y=0;
	while(i<=c1&&j<=c2){
		if(x<y){
			i++;
			if(a[i].c==b[j].c) ans+=min(a[i].len,y-x);
			x+=a[i].len;
		}else if(x>y){
			j++;
			if(a[i].c==b[j].c) ans+=min(b[j].len,x-y);
			y+=b[j].len;
		}else{
			i++;j++;
			x+=a[i].len;y+=b[j].len;
			if(a[i].c==b[j].c) ans+=min(a[i].len,b[j].len);
		}
	}
	cout<<S-ans;
}