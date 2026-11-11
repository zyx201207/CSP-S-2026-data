#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long cz[500017];
long long f[1017][1017];


long long f1[500017],f2[500017],mnz=0x3f3f3f3f3f3f3f3f,tim[500017][3];
//void find1(long long x){
//	return f1[x]==x?f1[x];f1[x]=find1(f1[x]);
//}
//void find2(long long x){
//	return f2[x]==x?f2[x];f2[x]=find2(f2[x]);
//}
void subc(){
	for(int i=1;i<=m;i++){
		f1[i]=f2[i]=i;
	}
	long long num,k,t;
	for(int i=1;i<=n;i++){
		
//		cin>>num;
		scanf("%lld",&num);
		scanf("%lld%lld",&k,&t);
//		cin>>k>>t;
		tim[k][i]=t;
		long long fa=k;
		for(int j=2;j<=num;j++){
			
			scanf("%lld%lld",&k,&t);
//			cin>>k>>t;
			tim[k][i]=t;
			if(i==1){
				f1[k]=fa;
			}else{
				f2[k]=fa;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(tim[i][1]!=0&&tim[i][2]!=0){
			mnz=min(tim[i][1]+tim[i][2],mnz);
		}
	}
	long long l,r;
	while(q--){
		scanf("%lld%lld",&l,&r);
//		cin>>l>>r;
		if(f1[l]==f1[r]||f2[l]==f2[r]){
//			cout<<cz[l]+cz[r]<<endl;
			printf("%lld\n",cz[l]+cz[r]);
		}else{
			printf("%lld\n",mnz+cz[l]+cz[r]);
//			cout<<mnz+cz[l]+cz[r]<<endl;
		}
	}
//	cout<<mnz<<endl;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
//	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
//		cin>>cz[i];
		scanf("%lld",&cz[i]);
	}
	if(c==20||c==21){
		subc();
		return 0;
	}
	for(int i=1;i<=m+n;i++){
		for(int j=1;j<=m+n;j++){
			if(i==j) continue;
			f[i][j]=0x3f3f3f3f3f3f3f3f;
		}
		
	}
	long long num,k,t;
	for(int i=1;i<=n;i++){
		
//		cin>>num;
		scanf("%lld",&num);
		for(int j=1;j<=num;j++){
//			cin>>k>>t;
			scanf("%lld%lld",&k,&t);
			f[k][i+m]=t;
			f[i+m][k]=t;
		}
	}
	for(int k=1;k<=m+n;k++){
		for(int i=1;i<=m+n;i++){
			for(int j=1;j<=m+n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	long long l,r;
	while(q--){
		
//		cin>>l>>r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",f[l][r]+cz[l]+cz[r]);
//		printf("\n"); 
//		cout<<f[l][r]+cz[l]+cz[r]<<endl;
	}
//	cout<<mnz<<endl;
	return 0;
}