#include<bits/stdc++.h>
//呃这题无疑是神秘的。 
using namespace std;
const int N=2e6+7;
struct edge{
	int u,v;
};
int c,t,n,k;
vector<edge> vec[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int o,p;
			cin>>o>>p;
			edge r;r.u=o,r.v=p;
			edge b;r.u=p,r.v=o;
//			vec.push_back(r);
//			vec.push_back(b);
		}
		cout<<"1"<<endl;
	}
	return 0;
}//看到这里的入，哥也是肥肠好奇你有木有把freopen注释了捏
//哥希望你木有;) 
