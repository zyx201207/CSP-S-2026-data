#include<bits/stdc++.h>
using namespace std;
struct s{
	long long v,n;
};
queue<s>q;
vector<long long>v;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	long long n,m;
	cin>>n>>m;
	long long na,num=1,l=0,ln=0,c=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	v.push_back(0);
	sort(a,a+n);
	na=a[0];
	for(int i=1;i<n+1;i++){
		if(a[i]==na){
			num++;
		}else{
			long long b=m;
			if(ln==0||l+v[v.size()-1]*(a[i-1]-a[i-num-1])<=b){
				s t;
				if(i-num!=0){
					t.n=ln;
					t.v=a[i-num-1];
				}
				q.push(t);
				l+=(v[v.size()-1]*(a[i-1]-a[i-num-1]));
				v.push_back(v[v.size()-1]+num);
			}else{
				s t1;
				t1.n=ln;
				t1.v=a[i-num-1];
				q.push(t1);
				long long n2=v[v.size()-1];
				long long t=l+v[v.size()-1]*(a[i-1]-a[i-num-1])-b;
				while(t>0){
					if(q.front().n*(a[i-1]-q.front().v)>t){
						if(t%(a[i-1]-q.front().v)==0){
							q.front().n-=(t/(a[i-1]-q.front().v));
							n2-=(t/(a[i-1]-q.front().v));
							t=0;
						}else{
							q.front().n-=(t/(a[i-1]-q.front().v)+1);
							n2-=(t/(a[i-1]-q.front().v)+1);
							t=(t/(a[i-1]-q.front().v)+1)*(a[i-1]-q.front().v)-t;
						}
						break;
					}else{
						t-=(q.front().n*(a[i-1]-q.front().v));
						n2-=q.front().n;
						q.pop();
					}
				}
				l=b-t;
				v.push_back(num+n2);
			}
			ln=num;
			num=1;
			na=a[i];
		}
	}
	long long maxn=0;
	for(int i=0;i<v.size();i++){
		maxn=max(maxn,v[i]);
	}
	cout<<maxn;
}
