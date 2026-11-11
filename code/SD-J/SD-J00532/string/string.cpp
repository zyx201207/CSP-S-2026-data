#include<bits/stdc++.h>
#define int long long
#define fi first
#define N 1001000
#define M 100100
#define P 998244353
#define PX 1000000007
#define se second
#define all(x) x.begin(),x.end()
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mod(x) (((x%P)+P)%P)
using namespace std;
int n,m,a[N],ans;
char c[N],rc[N],lc[N],xc[N],kc[N];
int r[N],l[N],lm,rm,nm,x[N],km,k[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	fst;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>c[i];
		n+=a[i];
	}
	if(n%2==1){
		
		int j=n/2;
		int res=0,lll,ll;
		for(int i=1;i<=m;i++){
			res+=a[i];
			if(res>=j){
				lll=i;
				break;
			}
			
		}res=0;
		for(int i=1;i<=m;i++){
			res+=a[i];
			if(res>j+1){
				ll=i;
				break;
			}
		}
		res=0;
		if(lll!=ll){
			for(int i=1,f=0,f2=0;i<=m;i++){
				res+=a[i];
				if(res>=j&&!f){
					if(res==j){
						l[++lm]=a[i];
						lc[lm]=c[i];
					}else{
						l[++lm]=a[i]-1;
						lc[lm]=c[i];
					}
					f=1;
					continue;
				}if(res>=j+2&&!f2){
					if(res-a[i]+1==j+1){
						r[++rm]=a[i]-1;
						rc[rm]=c[i];
					}else{
						r[++rm]=a[i];
						rc[rm]=c[i];
					}
					f2=1;
					continue;
				}
				if(!f){
					l[++lm]=a[i];
				lc[lm]=c[i];
				}else{
					r[++rm]=a[i];
				rc[rm]=c[i];
				}
				
			}			
		}else{
			for(int i=1,f=0;i<=m;i++){
				res+=a[i];
				if(res>=j&&!f){
					l[++lm]=j-res+a[i];
					lc[lm]=c[i];
					r[++rm]=res-j-1;
					rc[rm]=c[i];
					f=1;
					continue;
				}
				if(!f){
					l[++lm]=a[i];
					lc[lm]=c[i];
				}else{
					r[++rm]=a[i];
					rc[rm]=c[i];
				}
			}
		}
	}else{
		int j=n/2;
		int res=0;
		for(int i=1,f=0;i<=m;i++){
			res+=a[i];
			if(res>j&&!f){
				l[++lm]=j-res+a[i];
				lc[lm]=c[i];
				r[++rm]=res-j;
				rc[rm]=c[i];
				f=1;
				continue;
			}if(res==j&&!f){
				l[++lm]=a[i];
				lc[lm]=c[i];
				f=1;
				continue;
			}
			if(!f){
				l[++lm]=a[i];
				lc[lm]=c[i];
			}else{
				r[++rm]=a[i];
				rc[rm]=c[i];
			}
		}
	}
//	cout<<"l:\n";
//	for(int i=1;i<=lm;i++){
//		cout<<l[i]<<' '<<lc[i]<<endl;
//	}
//	cout<<"r:\n";
//	for(int i=1;i<=rm;i++){
//		cout<<r[i]<<' '<<rc[i]<<endl;
//	}
	nm=lm;
	for(int i=1;i<=lm;i++){
		x[i]=l[i];
		xc[i]=lc[i];
	}
	km=rm;
	for(int i=1;i<=rm;i++){
		k[i]=r[i];
		kc[i]=rc[i];
	}
	reverse(x+1,x+1+nm);
	reverse(xc+1,xc+1+nm);
	int ans1=0;
	for(int i=1,j=1;i<=km&&j<=nm;){
		if(k[i]>x[j]){
			if(kc[i]!=xc[j])ans1+=x[j];
			k[i]-=x[j];
			j++;
			if(!k[i])i++;
		}else{
			if(kc[i]!=xc[j])ans1+=k[i];
			x[j]-=k[i];
			i++;
			if(!x[j])j++;
		}
	}
	nm=rm;
	for(int i=1;i<=rm;i++){
		x[i]=r[i];
		xc[i]=rc[i];
	}
	km=lm;
	for(int i=1;i<=lm;i++){
		k[i]=l[i];
		kc[i]=lc[i];
	}
	reverse(x+1,x+1+nm);
	reverse(xc+1,xc+1+nm);
	int ans2=0;
	for(int i=1,j=1;i<=km&&j<=nm;){
		if(k[i]>x[j]){
			if(kc[i]!=xc[j])ans2+=x[j];
			k[i]-=x[j];
			j++;
			if(!k[i])i++;
		}else{
			if(kc[i]!=xc[j])ans2+=k[i];
			x[j]-=k[i];
			i++;
			if(!x[j])j++;
		}
	}
	cout<<min(ans1,ans2);
	return 0;
}

