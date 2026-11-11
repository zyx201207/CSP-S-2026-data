#include<iostream>
#include<deque>
using namespace std;
typedef long long ll;
struct ch{
	ll sum;
	char c;
};
ll n,ans;
deque<ch> d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		ch a;
		cin>>a.sum>>a.c;
		d.push_back(a);
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	while(d.size()>1){
		ch x=d.front(),y=d.back(),m;
		bool v=false;
		if(x.sum<y.sum)
			m=x;
		else if(x.sum>y.sum)
			m=y;
		else{
			v=1;
			m=x;
		}
		if(x.c!=y.c)
			ans+=m.sum;
		if(v){
			d.pop_front();
			d.pop_back();
		}
		else if(m.sum==x.sum&&m.c==x.c){
			d[d.size()-1].sum-=m.sum;
			d.pop_front();
		}
		else{
			d[0].sum-=m.sum;
			d.pop_back();
		}
		
	}
	cout<<ans;
	return 0;
} 
