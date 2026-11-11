#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
long long a[2000044],sl,s[2000044][4];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	c=read();t=read();
	while(t--){
		long long z,x,ans=0;
		z=read();x=read();
		for(int i=1;i<=z;i++){
			a[i]=read();
		}
		int wzz=1,la=0;
		while(wzz<=z){
			map<long long,bool> pd;
			while(wzz<z&&a[wzz+1]-a[wzz]<=x)wzz++;
			sl=0;
			for(int i=la+1;i<wzz;i++){
//				if(a[i]-a[i-3]>x&&a[i]-a[i-1]<=x&&a[i]-a[i-2]<=x&&a[i-1]-a[i-3]<=x&&a[i-2]-a[i-3]<=x){
//					sl++;
//					s[sl][0]=i-3;s[sl][3]=i;
//					s[sl][1]=i-2;s[sl][2]=i-1;
//				}
				long long l=i+1,r=wzz,mid,wz=-1;
				while(l<=r){
					mid=(l+r)>>1;
					if(a[mid]-a[i]<=x){
						wz=mid;
						l=mid+1;
					}
					else r=mid-1;
				}
				if(wz==-1||wz==i+1)continue;
				wz--;
				l=wz+2,r=wzz;
				long long wzi=-1;
				while(l<=r){
					mid=(l+r)>>1;
					if(a[mid]-a[wz]<=x){
						wzi=mid;
						l=mid+1;
					}
					else r=mid-1;
				}
				l=wz+2,r=wzi;wzi=-1;
				wz--;
				while(l<=r){
					mid=(l+r)>>1;
					if(a[mid]-a[wz]>x){
						wzi=mid;
						r=mid-1;
					}
					else l=mid+1;
				}
				if(wzi!=-1){
					if(pd[wzi]==1)sl--;
					pd[wzi]=1;
					sl++;
					s[sl][0]=i;s[sl][1]=wz+1;s[sl][2]=wz+2;s[sl][3]=wzi;
				}
			}
			int wz2j=1,wz1j=0;
			int la1=0,la2=0,la3=0;
			for(int i=1;i<=sl;i++){
				//while(wz2j<=sl&&s[wz2j][0]<s[i][2])wz2j++;
				//while(wz1j<sl&&s[wz1j+1][3]<=s[i][1])wz1j++;
				long long li,lj,ri,rj,lk,rk;
				if(i==1)li=la;
				else li=s[i-1][0];
				if(i==sl)ri=wzz+1;
				else ri=s[i+1][3];
				long long l=la+1,r=s[i][0],mid,wz=-1;
				while(l<=r){
					mid=(l+r)>>1;
					if(a[s[i][2]]-a[mid]<=x){
						r=mid-1;
					}
					else{
						l=mid+1;
						wz=mid;
					}
				}
				if(wz==-1)wz=la;
				if(a[s[i][1]]-a[wz]>x){
					lj=la;li=la;
					if(la1!=0){
						lj=s[la1][0];li=lj;
						//ans+=la2*(s[i][3]-(s[la1][3])-la3);
					}
				}
				else lj=wz;
				l=s[i][3],r=wzz,wz=-1;
				while(l<=r){
					mid=(l+r)>>1;
					if(a[mid]-a[s[i][1]]<=x){
						l=mid+1;
					}
					else{
						r=mid-1;
						wz=mid;
					}
				}
				if(wz==-1)wz=wzz+1;
				if(a[wz]-a[s[i][2]]>x){
					rj=wzz+1;
					la1=i;
				}
				else rj=wz;
				lk=max(li,lj);rk=min(ri,rj);
				if(la1==i){
					la2=(s[i][0]-lk);la3=(rk-(s[i][3]));
				}
				ans+=(s[i][0]-lk)*(rk-(s[i][3]));
				//cout<<s[i][0]<<" "<<s[i][1]<<" "<<s[i][2]<<" "<<s[i][3]<<" "<<(s[i][0]-lk)*(rk-(s[i][3]))<<"\n";
				//cout<<lk<<" "<<rk<<"\n";
			}
			la=wzz;wzz++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}