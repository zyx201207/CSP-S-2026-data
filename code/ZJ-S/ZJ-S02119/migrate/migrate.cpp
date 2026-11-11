#include<bits/stdc++.h>
using namespace std;
long long c,t,w[2000006],n,d,ans=0;int ll[2000006],rr[2000006],tt[2000006];
inline long long read(){
	int c;c=getchar();long long ans=0,f=1;
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar_unlocked();
	}
	while(isdigit(c)){
		ans=ans*10+c-'0';
		c=getchar_unlocked();//getchar_unlocked
	}
	return ans*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	int l,r,mid;
	while(t--){
		ans=0;
		n=read();d=read();
		for(int i=1;i<=n;i++){
			w[i]=read();tt[i]=0;
			
		}
		for(int i=1;i<=n;i++){
			l=1;r=i;
			while(l<r){
				mid=((l+r)>>1);
				if(w[mid]+d<w[i]){
					l=mid+1;
				}
				else r=mid;
			}
			ll[i]=l;
				l=i;r=n;
				while(l<r){
					mid=((l+r)>>1)+1;
					if(w[i]+d<w[mid]){
						r=mid-1;
					}
					else l=mid;
				}
				rr[i]=l;
			tt[rr[i]]+=1;
			//cout<<ll[i]<<" "<<rr[i]<<endl;
		}
	//	cout<<"\n";
		for(int i=1;i<=n;i++){
			if(i-ll[i]<2)continue;
			ans+=tt[ll[i]+1];
			if(rr[ll[i]]==ll[i]+1)ans--;
		}
		printf("%lld\n",ans);
	}
	
}
