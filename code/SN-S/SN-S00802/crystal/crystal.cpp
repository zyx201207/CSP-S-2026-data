#include<bits/stdc++.h>
using namespace std;

long long n,j5,a[500010],j1[500010],p,h;
//,j7[500010],di[500010],
long long j2,j3;

int j6;
int u,b;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>j5;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	
	j1[0]=0;
	j1[1]=a[0];
	for(int i=1;i<n;i++){
		j1[i+1]=a[i]+j1[i];
	}
	/*for(int i=1;i<n-1;i++){
		while(m>a[j2]-a[j3-1] ||m>(j2-j3+1)(a[j2]-a[j2+1])){
			if(m>a[j2]-a[j3-1] &&m>(j2-j3+1)(a[j2]-a[j2+1])){
				if((a[j2]-a[j3-1]>(j2-j3+1)(a[j2]-a[j2+1] &&j2<=n-2) ||j3==0){
					j2++;
					m-=(j2-j3+1)(a[j2]-a[j2+1];
				}else if((a[j2]-a[j3-1]<=(j2-j3+1)(a[j2]-a[j2+1] &&j3>=1) ||j2==n-1){
					j3--;
					m-=a[j2]-a[j3-1];
				}
				}
			}
		}
	}
	*/
	
	
	for(int i=0;i<n;i++){
		u=n-1;
		h=i;
		b=0;
		while(h<u){
			p=(h+u+1)/2;
			if(a[p]*(p-i+1)-j1[p+1]+j1[i]<j5){
				h=p;
			}
			if(a[p]*(p-i+1)-j1[p+1]+j1[i]>j5){
				u=p-1;
			}
			
			if(a[p]*(p-i+1)-j1[p+1]+j1[i]==j5){
				u=p;
				b=-1;
				break;
			}
		}

		j6=max(j6,u-i+1-b);
	}
	cout<<j6;
	return 0;
}

 
