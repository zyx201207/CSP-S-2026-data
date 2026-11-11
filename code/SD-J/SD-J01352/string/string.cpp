#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=2e5+10;
struct Node{
	int a;
	char c;
}a[Maxn];
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++)	cin>>a[i].a>>a[i].c; 
	for(int i=1;i<=n;i++)	sum+=a[i].a;
	vector <Node> l,r;
	for(int i=1;i<=n;i++){
		if(cnt+a[i].a<=sum/2){
			cnt+=a[i].a;
			l.push_back(a[i]);
		}else{
			if(cnt!=sum/2){
				Node x;x.c=a[i].c;x.a=sum/2-cnt;
				a[i].a-=x.a;
				l.push_back(x);
			}
			if(a[i].a==0)	i++;
			if(sum%2==1)	a[i].a--;
			if(a[i].a==0)	i++;
			for(int j=i;j<=n;j++){
				r.push_back(a[j]);
			}
			break;
		}
	}
	//¼ìÑé
//	cout<<"\n";
//	for(auto it:l)	cout<<it.a<<" "<<it.c<<"\n";
//	cout<<"\n";
//	for(auto it:r)	cout<<it.a<<" "<<it.c<<"\n"; 
	int ans=0;
	int pl=0,pr=r.size()-1;
	while(pl<l.size()&&pr>=0){
		Node x=l[pl],y=r[pr];
		if(x.c!=y.c){
			if(x.a<y.a){
				r[pr].a=y.a-x.a;
				pl++;
				ans+=x.a;
			}else if(x.a==y.a){
				pr--;pl++;
				ans+=x.a;
			}else{
				l[pl].a=x.a-y.a;
				ans+=y.a;
				pr--; 
			}
		}else{
			if(x.a<y.a){
				pl++;
				r[pr].a=y.a-x.a;
			}else if(x.a==y.a){
				pr--;
				pl++;
			}else{
				pr--;
				l[pl].a=x.a-y.a;
			}
		}
//		cout<<ans<<"\n";
	}
	cout<<ans;
	return 0; 
}
/*
6
3 a
3 b
3 c
2 a
3 c
2 b
*/
