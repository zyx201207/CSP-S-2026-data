//SN-J01034 马星辰 西安市曲江第一学校 
#include <bits/stdc++.h>
using namespace std;
int n,cnt,mid,a[200010];
long long l,ans;
string s;
char c[200010],d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i = 1;i <= n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	l/=2;
	long long sum=0;
	for (int i = 1;i <= n;i++){
		sum+=a[i];
		if (sum>=l){
			mid=i;
			break;
		}
	}
	for (int z=1,f=n;;){
		int maxx=max(a[z],a[f]),minn=min(a[z],a[f]);
		if (z!=mid&&f!=mid){
			if (c[z]==c[f]){
				if (a[z]>a[f]){
					a[z]-=a[f];
					a[f]=0;
					f--;
				}
				else if (a[f]>a[z]){
					a[f]-=a[z];
					a[z]=0;
					z++;
				}
				else {
					a[z]=0,a[f]=0;
					z++;
					f--;
				}
			}
			else {
				if (a[z]>a[f]){
					ans+=a[f];
					a[z]-=a[f];
				
					a[f]=0;
					f--;
				}
				else if (a[f]>a[z]){
					ans+=a[z];
					a[f]-=a[z];
					a[z]=0;
					z++;
				}
				else{
					ans+=a[z];
					a[z]=0;
					a[f]=0;
					z++,f--;
				}
			}
		}
		else if (z==mid&&f!=mid){
			if (c[z]!=c[f]){
				ans+=a[f];
				a[z]-=a[f];
				
				a[f]=0;
				f--;
			}
			else {
				a[z]-=a[f];
				a[f]=0;
				f--;
			}
		}
		else if (f==mid&&z!=mid){
			if (c[z]!=c[f]){
				ans+=a[z];
				a[f]-=a[z];
				a[z]=0;
				z++;
			}
			else {
				a[f]-=a[z];
				a[z]=0;
				z++;
			}
		}
		else break;
	}
	cout<<ans;
	return 0;
} 
