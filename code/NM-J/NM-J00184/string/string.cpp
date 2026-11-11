#include<bits/stdc++.h>
using namespace std;
char a[300000][10];
long long x,b[300000];
vector<pair<long long,char> >v,w,v1,w1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&x);
	long long l=0;
	for(int i=0;i<x;i++){
		scanf("%lld%s",&b[i],a[i]);
		l+=b[i];
	}
	long long r=x-1,dq=0;
	for(int i=0;i<x;i++){
		if(dq>l/2){
			r=i;
			break;
		}
		dq+=b[i];
	}
	dq=0;
	for(int i=0;i<x;i++){
		if(dq+b[i]>l/2){
            if(l%2==0){
                if(l/2-dq!=0){
                    v.push_back({l/2-dq,a[i][0]});
                }
                if(b[i]-(l/2-dq)!=0){
                    w.push_back({b[i]-(l/2-dq),a[i][0]});
                }
            }
            else{
                if(l/2-dq!=0){
                    v.push_back({l/2-dq,a[i][0]});
                }
                if(b[i]-(l/2-dq)-1!=0){
                    w.push_back({b[i]-(l/2-dq)-1,a[i][0]});
                }
            }
			break;
		}
		v.push_back({b[i],a[i][0]});
		dq+=b[i];
	}
	for(int i=r;i<x;i++){
		w.push_back({b[i],a[i][0]});
	}
	l=0;
	r=(int)w.size()-1;
	while(l<v.size() and r>-1){
		long long t=min(v[l].first,w[r].first);
		v1.push_back({t,v[l].second});
		w1.push_back({t,w[r].second});
		v[l].first-=t;
		w[r].first-=t;
		if(v[l].first==0){
			l++;
		}
		if(w[r].first==0){
			r--;
		}
	}
	long long ans=0;
	for(int i=0,k=0;i<v1.size();i++,k++){
		if(v1[i].second!=w1[k].second){
			ans+=v1[i].first;
		}
	}
	printf("%lld",ans);
    return 0;
}
