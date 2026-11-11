#include<bits/stdc++.h>
using namespace std;
long long n,sum,sum1,a[200010],h;
char s,c[200010];
long long ans;
int main(){
	freopen("string.in","r",stdin),freopen("string.out","w",stdout);
	cin>>n;
	c[0]='.';
	for(int i=1;i<=n;i++)
	{   cin>>sum>>s;
		if(s==c[h])a[h]+=sum;
		else a[++h]=sum,c[h]=s;
	}
	int l=1,r=h;
	while(l<=r){
		if(a[l]==a[r]){
			if(c[l]!=c[r])ans+=a[l];
			l++,r--;
		}
		else if(a[l]>a[r]){
			sum=0,sum1=0;//sum遍历的   sum1修改的 
			for(;sum<a[l];)
			{   if(sum+a[r]<=a[l]){
					if(c[r]!=c[l])sum1+=a[r];
					sum+=a[r],r--;
				}
				else {
					if(c[r]!=c[l])sum1+=(a[l]-sum);
					a[r]-=(a[l]-sum),sum=a[l];
					break;
				}
			}
			l++;
			ans+=sum1;
		}
		else {
			sum=0,sum1=0;//sum遍历的   sum1修改的 
			for(;sum<a[r];)
			{   if(sum+a[l]<=a[r]){
					if(c[l]!=c[r])sum1+=a[l];
					sum+=a[l],l++;
				}
				else {
					if(c[l]!=c[r])sum1+=(a[r]-sum);
					a[l]-=(a[r]-sum),sum=a[r];
					break;
				}
			}
			r--;
			ans+=sum1;
		}
	}
	cout<<ans;
	return 0;
}

