#include<bits/stdc++.h>
using namespace std;
long long n,m,k,num=0;
long long a,ans;
queue<pair<long long,short> > t,ut,em;
bool p;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a;
		t.push({a,0});
	}
	for(int i=31;i>=0;i--){
		//cout<<i<<endl;
		while(!t.empty() && t.front().second!=i%2){
			if(((t.front().first)>>i)&1){
				t.push({t.front().first,i%2});
				if(num<=10){
					//cout<<i<<" ------t--add-- "<<t.front().first<<" "<<i%2<<endl;
					num++;
				}
			}
			else{
				ut.push({t.front().first,i%2});
				if(num<=10){
					//cout<<i<<" ------ut--add-- "<<t.front().first<<" "<<i%2<<endl;
					num++;
				}
			}
			t.pop();
		}
		if(t.size()>=m){
			ut=em;
		}
		else{
			while(!ut.empty()){
				t.push(ut.front());
				ut.pop();
			}
		}
	}
	ans=t.front().first;
	t.pop();
	m-=1;
	while(m--){
		ans&=t.front().first;
		t.pop();
	}
	cout<<ans;
	return 0;
}

