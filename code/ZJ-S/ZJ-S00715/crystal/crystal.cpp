#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
long long a[maxn];
unsigned long long de[maxn];
unsigned long long n,m;
struct shu{
	int zhi;
	long long c;
};
unsigned long long max(unsigned long long a,unsigned long long b){
	return a>b?a:b;
}
void solve(){
	long long ans=1;
	unsigned long long def=0;
	long long l=n-2,r=n-1;
	unsigned long long count=de[n-1]+de[n-2];
	vector<shu> d;
	long long f=0;
	while(1){
		if(count<=m){
			if(count==m) ans=max(ans,r-l+1);
			else{
				if((m-count)%(r-l+1)==0) ans=max(ans,r-l+1);
			}
			l--;
			if(l<0) break;
			else{
				count+=de[l]-def;
				if(de[l]==de[l+1]){
					if(f<d.size() && d[f].zhi==de[l]) d[f].c++;
					else{
						shu temp;
						temp.zhi=de[l];
						temp.c=1;
						d.push_back(temp);
					}
				}
			} 
		}
		else{
			r--;
			if(!d.empty() && de[r+1]==d[f].zhi){
				r-=d[f].c;
				f++;
			} 
			count-=de[r]*(r-l+1);
			def+=de[r];
			if(l==r){
				l--;
				if(l<0) break;
				else count+=de[l]-def;
			}	
		}
	}
	cout<<ans;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	de[n-1]=0;
	for(int i=n-2;i>=0;i--) de[i]=a[n-1]-a[i];
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}