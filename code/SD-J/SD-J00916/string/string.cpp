#include<bits/stdc++.h>
using namespace std;

long long t;
long long len;
long long ans;
vector<pair<long long,char> > v;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>t;
	string s;
	for(long long i=0;i<t;i++){
		long long a;
		cin>>a;
		char c;
		cin>>c;
		len+=a;
		v.push_back({a,c});
		
	}
//	cout<<s<<" "<<len<<"\n";
	queue<pair<long long,char> > vl,vr;
	long long ll=0,rr=0;
	long long l=0,r=t-1;
	long long mid=len/2;
	
//	cout<<mid<<"\n\n";
	
	while(ll<mid){
		if(ll+v[l].first<=mid){
			ll+=v[l].first;
			vl.push(v[l++]);
			
		}
		else{
			vl.push({mid,v[l].second});
			break;
		}
	}
	while(rr<mid){
		if(rr+v[r].first<=mid){
			rr+=v[r].first;
			vr.push(v[r--]);
			
		}
		else{
			vr.push({mid,v[r].second});
			break;
		}
	}
	
//	cout<<vl.size();
	
//	while(!vl.empty()){
//		cout<<vl.front().first<<" "<<vl.front().second<<"\n";
//		vl.pop();
//	}
//	cout<<"\n";
//	while(!vr.empty()){
//		cout<<vr.front().first<<" "<<vr.front().second<<"\n";
//		vr.pop();
//	}
//	cout<<"\n";
	
	while(!vl.empty()&&!vr.empty()){
		if(vl.front().first>vr.front().first){
			if(vl.front().second!=vr.front().second){
				ans+=vr.front().first;
				vl.front().first-=vr.front().first;
				vr.pop();
			}
			else{
				if(vl.front().first!=vr.front().second){
					vl.front().first-=vr.front().first;
					vr.pop();
				}
			}
		}
		else if(vl.front().first<vr.front().first){
			if(vl.front().second!=vr.front().second){
				ans+=vl.front().first;
				vr.front().first-=vl.front().first;
				vl.pop();
			}
			else{
				if(vl.front().first!=vr.front().second){
					vr.front().first-=vl.front().first;
					vl.pop();
				}
			}
		}
		else{
			if(vl.front().second!=vr.front().second){
				ans+=vr.front().first;
				vr.pop();vl.pop();
			}
			else{
				vr.pop();vl.pop();
			}
		}
	}
	cout<<ans;
	return 0;
}

