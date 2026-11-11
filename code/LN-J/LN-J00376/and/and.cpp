#include<bits/stdc++.h>
#define yqf using
#define love namespace
#define sjw std
yqf love sjw;
#define int unsigned long long
vector<int>x;
bool cmp(int x,int y){
	return x>y;
}
int n,m,ans;
signed main(){
    
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
	int foo;
	cin>>foo;
	x.push_back(foo);
    }
    sort(x.begin(),x.end(),cmp);
    ans=x[0];
    //cout<<"Ans="<<ans<<endl;
    for(int i=1;i<m;i++){
	ans&=x[i];
	//cout<<ans<<' '<<x[i]<<endl;
    }
    //cout<<endl;
    cout<<ans<<endl;
    return 0;
}
