#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int lastl=0,lastr=0;
	for(int i=1,j=n;i<=j;){
		if(lastl>=a[j]){
			if(c[i-1]!=c[j])ans+=a[j];
			lastl-=a[j];
			j--;
		}else if(lastr>=a[i]){
			if(c[i]!=c[j+1])ans+=a[i];
			lastr-=a[i];
			i++;
		}else if(i==j){
			if(lastl!=0){
				if(c[i-1]!=c[j])ans+=lastl;
			}
			else if(lastr!=0){
				if(c[i]!=c[j+1])ans+=lastr;
			}
			break;
		}else{
			if(a[i]+lastl>a[j]+lastr){
				if(lastl==0){
					if(lastr==0){
						if(c[i]!=c[j])ans+=a[j];
					}else{
						if(c[i]!=c[j+1])ans+=lastr;
						if(c[i]!=c[j])ans+=a[j];
					}
				}else if(lastr==0){
					if(c[i-1]!=c[j])ans+=lastl;
					if(c[i]!=c[j])ans+=a[j]-lastl;
				}
				lastl=a[i]+lastl-a[j]-lastr;
				lastr=0;
			}
			else if(a[i]+lastl<a[j]+lastr){
				if(lastl==0){
					if(lastr==0){
						if(c[i]!=c[j])ans+=a[i];
					}else{
						if(c[i]!=c[j+1])ans+=lastr;
						if(c[i]!=c[j])ans+=a[i]-lastr;
					}
				}else if(lastr==0){
					if(c[i-1]!=c[j])ans+=lastl;
					if(c[i]!=c[j])ans+=a[i];
				}
				lastr=a[j]+lastr-a[i]-lastl;
				lastl=0;
			}else{
				if(lastl==0){
					if(lastr==0){
						if(c[i]!=c[j])ans+=a[j];
					}else{
						if(c[i]!=c[j+1])ans+=lastr;
						if(c[i]!=c[j])ans+=a[j];
					}
				}else if(lastr==0){
					if(c[i-1]!=c[j])ans+=lastl;
					if(c[i]!=c[j])ans+=a[i];
				}
				lastr=lastl=0;
			}
			i++;j--;
		}
	}
	cout<<ans;
}
