#include<bits/stdc++.h>
using namespace std;
int n,shuru,k=0,flag=0,u=-1,flagflag=0,mc;
long long m,gh,gt;
struct x{
	long long a;
	char b;
};
x l[200005];
int c(long long h,long long t,long long sum,long long gh,long long gt){
	if(gh==-1 and gt==-1){
		h++;
		gh=l[h].a-l[h-1].a;
		t--;
		gt=l[t+1].a-l[t].a;
		if(gh>gt){
			if(l[h].b!=l[t].b){
				sum+=gt;
			}
			return c(h,t-1,sum,gh-gt,l[t].a-l[t-1].a);
		}
		if(gh=gt){
			if(l[h].b!=l[t].b){
				sum+=gt;
			}
			return c(h+1,t-1,sum,l[h+1].a-l[h].a,l[t].a-l[t-1].a);
		}
		if(gh<gt){
			if(l[h].b!=l[t].b){
				sum+=gh;
			}
			return c(h+1,t,sum,l[h+1].a-l[h].a,gt-gh);
		}
		if(h>=m or t<=m){
			return sum;
		}
	}
	if(h>=m or t<=m){
		if(l[h].b!=l[h].a){
			return sum+gh;
		}
		return sum;
	}
	if(gh>gt){
		if(l[h].b!=l[t].b){
			sum+=gt;
		}
		return c(h,t-1,sum,gh-gt,l[t-1].a);
	}
	if(gh=gt){
		if(l[h].b!=l[t].b){
			sum+=gt;
		}
		return c(h+1,t-1,sum,l[h+1].a,l[t-1].a);
	}
	if(gh<gt){
		if(l[h].b!=l[t].b){
			sum+=gh;
		}
		return c(h+1,t,sum,l[h+1].a,gt-gh);
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	l[0].a=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>shuru>>l[i].b;
		l[i].a=l[i-1].a+shuru;
	}
	if(l[n].a%2==0){
		m=l[n].a/2;
		for(int i=1;i<=n;i++){
			if(l[i].a==m){
				mc=i;
				break;
			}
			if(l[i].a>m){
				mc=i;
				for(int j=n+1;j>mc;j--){
					l[j].b=l[j-1].b;
					l[j].a=l[j-1].a;
				}
				n++;
				l[mc].a=m;
				break;
			}
		}
	}
	else{
		m=(l[n].a+1)/2;
		for(int i=1;i<=n;i++){
			if(l[i].a==m){
				if(l[i].a-l[i-1].a==1){
					for(int j=i;j<=n;j++){
						l[j].a=l[j+1].a-1;
						l[j].b=l[j+1].b;
					}
					n--;
					mc=i-1;
				}
				else{
					for(int j=i;j<=n;j++){
						l[j].a--;
					}
					if(l[i].a<=i){
						mc=i+1;
					}
					else{
						mc=i+1;
					}
				}
				break;
			}
			if(l[i].a>m){
				for(int j=i;j<=n;j++){
					l[j].a--;
				}
				mc=i;
				for(int j=n+1;j>mc;j--){
					l[j].b=l[j-1].b;
					l[j].a=l[j-1].a;
				}
				n++;
				l[mc].a=m;
			}
		}
	}
	cout<<c(0,n,0,-1,-1);
	return 0;
}
