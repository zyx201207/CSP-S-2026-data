#include<bits/stdc++.h>
#define int long long
using namespace std; 
struct node{
	int a;
	char c;
	int start,end;
};
int ans=0;
node a[1000005];
vector<char>c;
int n;
int len;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		len+=a[i].a;
	}
	int mid=(len+1)/2;
	int midi=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		int sum1=sum;
		sum+=a[i].a;
		a[i].start=sum1+1;
		a[i].end=sum;
		if(sum1<=mid&&sum>=mid){
			midi=i;
			break;
		}
	}
	if(len<=100000000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].a;j++){
				c.push_back(a[i].c);
			}
		}
		int mid=(len+1)/2;
		int midi=0;
		int sum=0;
		for(int l=0,r=c.size()-1;l<=r;l++,r--){
			if(c[l]!=c[r]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int li=1,ri=n;li<=ri;){
		int minn=min(a[li].a,a[ri].a);
		if(a[li].c!=a[ri].c){
			ans+=minn;
		}                                         
		if(a[li].a==a[ri].a){
			li++;
			ri--;
			continue;
		}
		else if(a[li].a==minn){
			li++;
			a[ri].a-=minn;
		}
		else if(a[ri].a==minn){
			ri--;
			a[li].a-=minn;
		}
	}
	cout<<ans;
}
