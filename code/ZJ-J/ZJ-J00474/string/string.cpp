#include <bits/stdc++.h>
using namespace std;
long long c=0;
int m1[200010];
char m2[200010];
int n,a[200010],m=0,b[200010];
char x[200010],y[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> x[i];
		b[n-i+1]=a[i];
		y[n-i+1]=x[i];
	}
	int c1=0,c2=0;
	bool bo;
	for(int i=1;i<=2*n;i++){
		if(m1[i]==0){
			if(x[i-c1]!=y[i-c2]){
				c+=min(a[i+c1],b[i+c2]);
			}
			if(a[i-c1]==b[i-c2]){
				continue;
			}
			if(a[i-c1]>b[i-c2]){
				m1[i+1]=a[i-c1]-b[i-c2];
				m2[i+1]=x[i-c1];
				if(bo==false){
					c1--;
				}
				bo=false;
				c1++;
			}else{
				m1[i+1]=b[i-c2]-a[i-c1];
				m2[i+1]=y[i-c2];
				if(bo==true){
					c2--;
				}
				bo=true;
				c2++;
			}
		}else{
			if(bo){
				if(x[i-c1]!=m2[i]){
					c+=min(m1[i],a[i-c1]);
				}
				if(a[i-c1]==m1[i]){
					continue;
				}
				if(a[i+c1]>m1[i]){
					m1[i+1]=a[i-c1]-m1[i];
					m2[i+1]=x[i-c1];
					if(bo==false){
						c1--;
					}
					bo=false;
					c1++;
				}else{
					m1[i+1]=m1[i]-a[i-c1];
					m2[i+1]=m2[i];
					if(bo==true){
						c2--;
					}
					bo=true;
					c2++;
				}
			}else{
				if(m2[i]!=y[i-c2]){
					c+=min(m1[i],b[i-c2]);
				}
				if(m1[i]==b[i-c2]){
					continue;
				}
				if(m1[i]>b[i-c2]){
					m1[i+1]=m1[i]-b[i-c2];
					m2[i+1]=m2[i];
					if(bo==false){
						c1--;
					}
					bo=false;
					c1++;
				}else{
					m1[i+1]=b[i-c2]-m1[i];
					m2[i+1]=y[i-c2];
					if(bo==true){
						c2--;
					}
					bo=true;
					c2++;
				}			
			}
		}
	}
	cout << c/2;
	return 0;
}


