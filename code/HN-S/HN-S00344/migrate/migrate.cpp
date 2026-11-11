#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000006],xm[2000006],rr=0,y[2000006],ys=0,ts=0,us=0,dr=0;
long long kx[2000006],tz[2000006],uz[2000006],de[2000006],f[2000006],gon[2000006];
long long kx2[2000006],lt[2000006],rt[2000006],fa[2000006];
const long long czsyzx=999999999;
vector<long long> v[2000006];
inline long long cha(long long a1,long long b1){
	if(b1==0){
		if(kx[a1]==1){
			return 0;
		}
		return max(0ll,lt[a1]-rt[a1]);
	}
	else{
		return max(0ll,fa[a1]-lt[a1]);
	}
	return 0;
}
inline void abc(long long a1){
	long long es1,es2,es3,ex1,ex2,ex3,f1,f2,f3;
	f1=fa[a1];
	f2=fa[f1];
	f3=fa[f2];
	es1=kx[f1];
	es2=kx[f2];
	es3=kx[f3];
	ex1=kx2[f1];
	ex2=kx2[f2];
	ex3=kx2[f3];
	long long tt1;
	long long yt=tz[a1],yu=uz[a1];
	if(de[a1]>=2&&f1!=a1+1&&x[f2]-x[f1-1]<=d){
		kx2[f1]=1;
		tz[a1]=f1;	
		
		if(f1!=a1+2&&x[f2]-x[f1-2]<=d){
			uz[a1]=min(uz[a1],f1);	
		}
		if(yt<czsyzx){
			uz[a1]=min(uz[a1],yt);	
		}	
	}
	if(de[a1]>=2&&f1!=a1+1&&x[f2-1]-x[f1-1]<=d){
		//kx[f2]=1;
		if(kx2[f2]==1){
			uz[a1]=min(uz[a1],f2);	
		}			
	}
	if(de[a1]>=2){
		long long l=f1+1,r=f2,md=f1;
		while(l<=r){
			long long mid=(l+r)/2;
			if(f1!=a1+1&&x[mid]-x[f1-1]<=d){
				md=max(md,mid);
				l=mid+1;
			}			
			else{
				r=mid-1;
			}
		}	
		lt[f1]=md;
		l=f1+1,r=f2,md=f1;
		while(l<=r){
			long long mid=(l+r)/2;
			if(f1!=a1+2&&x[mid]-x[f1-2]<=d){
				md=max(md,mid);
				l=mid+1;
			}			
			else{
				r=mid-1;
			}
		}	
		rt[f1]=md;	
		f[a1]+=cha(f1,0);	
		//cout<<f[a1]<<" "<<f1<<" "<<cha(f1,0)<<" "<<rt[f1]<<" "<<lt[f1]<<" "<<uz[a1]<<" "<<tz[a1]<<endl;
	}
	if(uz[a1]<czsyzx){
		if(yu>czsyzx){
			tt1=uz[a1];
			while(de[tt1]!=0){
				//cout<<tt1<<endl;
				if(yt<czsyzx&&de[tt1]<de[yt]){
					f[a1]-=cha(tt1,1);
				}
				else{
					f[a1]-=cha(tt1,0);
				}
				tt1=fa[tt1];
			}
		}
		else{
			tt1=uz[a1];
			while(tt1!=yu){
				//cout<<tt1<<endl;
				if(yt<czsyzx&&de[tt1]<de[yt]){
					f[a1]-=cha(tt1,1);
				}
				else{
					f[a1]-=cha(tt1,0);
				}
				tt1=fa[tt1];
			}			
		}
	}
	if(tz[a1]<czsyzx&&tz[a1]!=uz[a1]){
		//cout<<1<<endl;
		if(yt>czsyzx){
			tt1=fa[tz[a1]];
			while(tt1!=uz[a1]&&de[tt1]!=0){
				if(yt<czsyzx&&de[tt1]<de[yt]){
					f[a1]-=cha(tt1,1);
				}
				else{
					//cout<<"11"<<" "<<tt1<<endl;
					f[a1]-=cha(tt1,0);
				}
				f[a1]+=cha(tt1,1);
				
				tt1=fa[tt1];
			}
		}
		else{
			tt1=fa[tz[a1]];
			while(tt1!=uz[a1]&&tt1!=fa[yt]){
				if(yt<czsyzx&&de[tt1]<de[yt]){
					f[a1]-=cha(tt1,1);
				}
				else{
					f[a1]-=cha(tt1,0);
				}
				f[a1]+=cha(tt1,1);
				//cout<<2<<endl;
				tt1=fa[tt1];
			}		
		}		
	}
	if(de[a1]>=2&&f1!=a1+1&&x[f2]-x[f1-1]<=d){
		kx2[f1]=1;
	}
	if(de[a1]>=2&&f1!=a1+1&&x[f2-1]-x[f1-1]<=d){
		kx[f2]=1;		
	}

	dr+=f[a1];
	for(int i=0;i<(int)v[a1].size();i++){
		long long tt=v[a1][i];
		de[tt]=de[a1]+1;
		f[tt]=f[a1];
		uz[tt]=uz[a1];
		tz[tt]=tz[a1];
		fa[tt]=a1;
		abc(tt);
	}
	kx[f1]=es1;
	kx[f2]=es2;
	kx[f3]=es3;
	kx2[f1]=ex1;
	kx2[f2]=ex2;
	kx2[f3]=ex3;
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			v[i].clear();
		}
		rr=1;
		for(int i=1;i<=n;i++){
			while(rr+1<=n&&x[rr+1]-x[i]<=d){
				rr++;
			}
			xm[i]=rr;
			if(rr!=i){
				v[rr].push_back(i);
			}
			kx[i]=0;
			tz[i]=uz[i]=1e18+7;
			gon[i]=0;
			lt[i]=rt[i]=i;
		}
		dr=0;
		for(int i=1;i<=n;i++){
			if(xm[i]==i){
				de[i]=0;
				f[i]=0;
				fa[i]=i;
				abc(i);
			}
		}
		for(int i=1;i<=n;i++){
			kx[i]=0;
			tz[i]=uz[i]=1e18+7;
			gon[i]=0;
			lt[i]=rt[i]=i;
			v[i].clear();		
				de[i]=0;
				f[i]=0;
				fa[i]=i;	
			//cout<<i<<" "<<uz[i]<<" "<<tz[i]<<" "<<cha(i,0)<<endl;
		}
		cout<<dr<<'\n';
	}
	return 0;
}
