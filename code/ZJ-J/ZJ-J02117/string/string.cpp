#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct rg{
	int cnt;
	char ch;
}a[N];
int sum=0,n,l=0;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cout.tie(0),cin.tie(0);
	cin>>n;
//	cout<<n<<'j';
	int x;
	char y;
	cin>>x>>y;
	sum+=x;
	a[++l].ch=y;
	a[l].cnt=x;
	for(int i=2;i<=n;i++){
//		cout<<'l';
		cin>>x;
		
		sum+=x;
		cin>>y;
		if(y==a[l].ch){
			a[l].cnt+=x;
//			cout<<y<<a[l].ch<<'g';
//			cout<<'t';
		}else{
			a[++l].ch=y;
			a[l].cnt=x;
		}
	}
//	cout<<l<<'\n';
//	for(int i=1;i<=l;i++) cout<<a[i].ch<<a[i].cnt<<' ';
//cout<<sum;
//	/*
	int ans=0;
	int i=1,ic=a[1].cnt,j=l,jc=a[l].cnt,cl=a[1].cnt,tl=a[l].cnt,tmp;
	bool v=0,k=0;
	while(!v||!k){
//		cout<<'t';
		if(cl>=sum/2){
			tmp=cl;
			cl=sum/2;
			ic-=tmp-cl;
			v=1;
//			cout<<'t'<<cl;
		}
		if(tl>=sum/2){
			tmp=tl;
			tl=sum/2;
			jc-=tmp-tl;
			k=1;
//			cout<<'t'<<cl;
		}
		if(a[i].ch!=a[j].ch){
			ans+=min(ic,jc);
		}
		if(ic<jc){
			tmp=ic;
			ic=0;
			jc-=tmp;
			i++;
			ic=a[i].cnt;
			cl+=ic;
			
		}else if(ic>jc){
			tmp=jc;
			ic-=jc;
			jc=0;
			j--;
			jc+=a[j].cnt;
			tl+=jc;
		}else{
			jc=0,ic=0;
			i++,j--;
			ic+=a[i].cnt;
			jc+=a[j].cnt;
			cl+=ic;
			tl+=jc;
		}
	}
	cout<<ans;
//	*/
//	cout<<ans;
	return 0;
}

