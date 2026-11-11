#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int ans,x,n,t,tot,t1,t2,f,cnt;
stack<pair<int,int> > st1,st2;
char c[N],y;
struct no{
	int num;
	char v;
}s1[N],s2[N],a[N];
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(NULL);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].v,tot+=a[i].num;
	}
	for(int i=1;i<=n;i++){
		if(cnt+a[i].num==tot/2&&f==0){
			if(tot%2==1) a[i+1].num--;
			t1++;
			s1[t1].num=a[i].num,s1[t1].v=a[i].v;
			f=1;
			continue;
		}
		if(cnt+a[i].num>tot/2&&f==0){
			if(tot%2==1) a[i].num--;
			t1++;
			s1[t1].num=tot/2-cnt,s1[t1].v=a[i].v;
			f=1;
			t2++;
			s2[t2].num=a[i].num+cnt-tot/2,s2[t2].v=a[i].v;
			continue;
		}
		cnt+=a[i].num;
		if(f==0){
			t1++;
			s1[t1].num=a[i].num;
			s1[t1].v=a[i].v;
		}
		else{
			t2++;
			s2[t2].num=a[i].num,s2[t2].v=a[i].v;
		}
	}
	for(int i=1;i<=t1;i++){
		st1.push(make_pair(s1[i].num,s1[i].v));
	}
	for(int i=t2;i>=1;i--){
		st2.push(make_pair(s2[i].num,s2[i].v));
	}
	while(st1.size()){
		int x1=st1.top().first,y1=st1.top().second,x2=st2.top().first,y2=st2.top().second; 
		if(y1==y2)
			if(x1==x2)
				st1.pop(),st2.pop();
			else{
				if(x1>x2){
					st1.pop(),st2.pop();
					st1.push(make_pair(x1-x2,y1));
				}
				else{
					st1.pop(),st2.pop();
					st2.push(make_pair(x2-x1,y2));
				}
			}
		if(y1!=y2){
			ans+=min(x1,x2);
			if(x1==x2)
				st1.pop(),st2.pop();
			else{
				if(x1>x2){
					st1.pop(),st2.pop();
					st1.push(make_pair(x1-x2,y1));
				}
				else{
					st1.pop(),st2.pop();
					st2.push(make_pair(x2-x1,y2));
				}
			}
		}
	}
	cout<<ans;
}
