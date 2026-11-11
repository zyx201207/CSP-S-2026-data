#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long tt,m50,m50_1,m50_2;
struct Note{
	long long len;
	char c;
}a[200005],b[200010];
//long long sum[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
//		sum[i]=sum[i-1]+a[i];
		tt+=a[i].len;
	}
	int L=0,R=0,f=0,fff=0,ffff=0;
	long long lenn1=0,lenn2=0,lennn=0,lennn1=0,xiab=0,xiab1=0;
	char c1,c2,cc,ccc;
	if(tt%2==0){
		m50_1=tt/2;
		m50_2=tt/2+1;
		long long temp=0;
		for(int i=1;i<=n;i++){
			temp+=a[i].len;
			if(temp==m50_1){
				long long ttt=temp;
				ttt-=a[i].len;
				lenn1=m50_1-ttt-1;
				c1=a[i].c;
				c2=a[i].c;
				lenn2=temp-m50_1+1;
				lennn=1;
				cc=a[i+1].c;
				lennn1=a[i+1].len-1;
				ccc=a[i+1].c;
				xiab=i;
				xiab1=i+1;
				ffff=1;
				break;
			}
			else if(temp>m50_1){
				long long ttt=temp;
				ttt-=a[i].len;
				lenn1=m50_1-ttt;
				c1=a[i].c;
				c2=a[i].c;
				lenn2=temp-m50_1;
				xiab=i;
				f=1;
				break;
			}
		}
	}
	else{
		m50=tt/2+1;
//		cout<<m50;
		long long temp=0;
		for(int i=1;i<=n;i++){
			temp+=a[i].len;
			if(temp==m50){
//				cout<<1<<'\n';
				long long ttt=temp;
				ttt-=a[i].len;
				lenn1=m50-ttt-1;
				c1=a[i].c;
				c2=a[i].c;
				lenn2=temp-m50+1;
				fff=1;
				xiab=i;
//				L=i;
//				R=i;
				break;
			}
			else if(temp>m50){
				long long ttt=temp;
				ttt-=a[i].len;
				lenn1=m50-ttt;
				c1=a[i].c;
				c2=a[i].c;
				lenn2=temp-m50;
				f=1;
				xiab=i;
				break;
			}
		}
	}
//	cout<<lenn1<<" "<<c1<<" "<<lenn2<<" "<<c2<<" "<<lennn<<" "<<cc<<'\n';
//	cout<<xiab<<'\n';
	if(f){
//		cout<<1;
		int ff=0;
		for(int i=1;i<=n+1;i++){
			if(i==xiab+1){
				continue;
			}
			if(xiab==i){
				b[i].c=c1;
				b[i].len=lenn1;
				b[i+1].c=c2;
				b[i+1].len=lenn2;
//				i=i+1;
				ff=1;
				if(tt%2==0){
					L=i;
					R=i+1;
				}
				else{
//					cout<<1<<'\n';
					L=i;
					R=i;
				}
			}
			else{
				if(ff){
					b[i].c=a[i-1].c;
					b[i].len=a[i-1].len;
				}
				else{
					b[i].c=a[i].c;
					b[i].len=a[i].len;
				}
			}
		}
	}
	if(fff){
		int ff=0;
		for(int i=1;i<=n+1;i++){
			if(i==xiab+1){
				continue;
			}
			if(xiab==i){
				b[i].c=c1;
				b[i].len=lenn1;
				b[i+1].c=c2;
				b[i+1].len=lenn2;
//				i=i+1;
				ff=1;
					L=i+1;
					R=i+1;
			}
			else{
				if(ff){
					b[i].c=a[i-1].c;
					b[i].len=a[i-1].len;
				}
				else{
					b[i].c=a[i].c;
					b[i].len=a[i].len;
				}
			}
		}
	}
	if(ffff){
		int ff=0;
		for(int i=1;i<=n+6;i++){
			if(i==xiab+1||i==xiab+2||i==xiab+3){
//				cout<<1<<'\n';
				continue;
			}
			if(xiab==i){
				b[i].c=c1;
				b[i].len=lenn1;
				b[i+1].c=c2;
				b[i+1].len=lenn2;
				b[i+2].c=cc;
				b[i+2].len=lennn;
				b[i+3].c=ccc;
				b[i+3].len=lennn1;
//				i=i+1;
				ff=1;
					L=i+1;
					R=i+2;
			}
			else{
				if(ff){
					b[i].c=a[i-2].c;
					b[i].len=a[i-2].len;
				}
				else{
					b[i].c=a[i].c;
					b[i].len=a[i].len;
				}
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			b[i].c=a[i].c;
			b[i].len=a[i].len;
		}
	}
//	for(int i=1;i<=n+3;i++){
//		cout<<b[i].len<<b[i].c<<'\n';
//	}
//cout<<L<<" "<<R<<'\n';
long long ans=0;
	if(ffff=0)
	while(L!=0&&R!=n+2){
		if(L==R){
			L--;
			R++;
			continue;
		}
//		cout<<L<<" "<<R<<'\n';
		if(b[L].len<b[R].len){
			if(b[L].c!=b[R].c){
				ans=ans+b[L].len;
				b[R].len=b[R].len-b[L].len;
				L--;
			}
			else{
				b[R].len=b[R].len-b[L].len;
				L--;
			}
		}
		else if(b[L].len==b[R].len){
//			cout<<1; 
			if(b[L].c!=b[R].c){
//				cout<<1<<" ";
				ans=ans+b[R].len;
				L--;
				R++;
			}
			else{
				L--;
				R++;
			}
		}
		else{
//			cout<<"1"<<'\n';
			if(b[L].c!=b[R].c){
				ans=ans+b[R].len;
				b[L].len=b[L].len-b[R].len;
				R++;
			}
			else{
				b[L].len=b[L].len-b[R].len;
				R++;
			}
		}
//		cout<<ans<<" ";
	}
	else{
		while(L!=0&&R!=n+3){
		if(L==R){
			L--;
			R++;
			continue;
		}
//		cout<<L<<" "<<R<<'\n';
		if(b[L].len<b[R].len){
			if(b[L].c!=b[R].c){
				ans=ans+b[L].len;
				b[R].len=b[R].len-b[L].len;
				L--;
			}
			else{
				b[R].len=b[R].len-b[L].len;
				L--;
			}
		}
		else if(b[L].len==b[R].len){
//			cout<<1; 
			if(b[L].c!=b[R].c){
//				cout<<1<<" ";
				ans=ans+b[R].len;
				L--;
				R++;
			}
			else{
				L--;
				R++;
			}
		}
		else{
//			cout<<"1"<<'\n';
			if(b[L].c!=b[R].c){
				ans=ans+b[R].len;
				b[L].len=b[L].len-b[R].len;
				R++;
			}
			else{
				b[L].len=b[L].len-b[R].len;
				R++;
			}
		}
//		cout<<ans<<" ";
	}
	}
	cout<<ans;
	return 0;
} 
