#include<bits/stdc++.h>
using namespace std;
struct node{
	long long front,rear;
};
vector<node> v[30];
int n,ans;
long long cnt;
bool cheak(long long f1,long long r1,long long f2,long long r2){
	if((f1<=r2&&f1>=f2)||(r1<=r2&&r1>=f2))return 1;
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,c;
		char b;
		cin>>a>>b;
		c=b-'a'+1;
		v[c].push_back({cnt+1,cnt+a});
		cnt+=a;
	}
	
	for(int i=1;i<=26;i++){
		if(v[i].size()==0)continue;
		long long it=0,ti=v[i].size()-1;
		while(it<=ti){
			long long f1=v[i][it].front,f2=v[i][ti].front,r1=v[i][it].rear,r2=v[i][ti].rear;
			if(cheak(f1,r1,cnt-r2+1,cnt-f2+1)){
				if(min(r1,cnt-f2+1)==(cnt+1)/2&&cnt%2)ans--;
				ans=ans+2*(min(r1,cnt-f2+1)-max(f1,cnt-r2+1)+1);
				if(cnt-r2+1>=f1)it++;
				else ti--;
			}
			else {
				if(cnt-r2+1>r1)it++;
				else ti--;
			}
		}
	}
	cout<<(cnt-ans)/2;
}