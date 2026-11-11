#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,sum,ans;
int a[200005],b[200005];
struct s{int num;int k;};
vector<s> vec1,vec2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		char c;cin>>c;
		b[i]=c-'a';
		sum+=a[i];
	}
	int x=0;sum/=2;
	for(int i=1;i<=n;i++){
		if(x+a[i]<sum)vec1.push_back({a[i],b[i]});
		else if(x+a[i]==sum){
			vec1.push_back({a[i],b[i]});
			break;
		}
		else {
			vec1.push_back({sum-x,b[i]});
			break;
		}
		x+=a[i];
	}
	x=0;
	for(int i=n;i>=1;i--){
		if(x+a[i]<sum)vec2.push_back({a[i],b[i]});
		else if(x+a[i]==sum){
			vec2.push_back({a[i],b[i]});
			break;
		}
		else {
			vec2.push_back({sum-x,b[i]});
			break;
		}
		x+=a[i];
	}
	int sz1=vec1.size(),sz2=vec2.size();
	for(int i=0,j=0;i<sz1,j<sz2;){
		int y=min(vec1[i].num,vec2[j].num);
		if(vec1[i].k!=vec2[j].k)ans+=y;
		vec1[i].num-=y;vec2[j].num-=y;
		if(vec1[i].num==0)i++;
		if(vec2[j].num==0)j++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}