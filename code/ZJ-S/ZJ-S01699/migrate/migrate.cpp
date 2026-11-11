#include<bits/stdc++.h>
using namespace std;
const int MAXN=2000005;
long long leng[MAXN];
//leng[i]:the distance from the ith island to 
//the (i+1)th island
int mark1[MAXN];
//It's for island,mark1[i] the 1Mark of the ith Island
//0:normal 1:start of able 
//2:end of able 
int mark2[MAXN];
//3:start of special 
//4:end of special
//Generally pos(4)-pos(3)=3
int mark3[MAXN],mark4[MAXN];

long long n,m;


bool debugmode=false;
void debug1(){
	if(debugmode==false)return;
	cout<<"<---debug start--->\n";
	for(int i=1;i<=n;i++){
		cout<<leng[i]<<" ";
	}
	cout<<endl;
	
	for(int i=1;i<=n;i++){
		cout<<mark1[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<mark3[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<mark4[i]<<" ";
	}
	cout<<"<---debug over--->"<<endl<<endl<<endl;
	
}


void init(){
	scanf("%lld %lld",&n,&m);
	long long lst,tmp,ans=0;
	for(long long i=1;i<=n;i++){
		mark1[i]=mark2[i]=mark3[i]=mark4[i]=0;
	}
	scanf("%lld",&lst);
	int tong=0;
	for(long long i=1;i<=n-1;i++){
		if(debugmode==true)cout<<lst<<" ";
		scanf("%lld",&tmp);
		leng[i]=tmp-lst;
		if(leng[i]<=m && tong == 0){
			tong=1;
			mark1[i]=1;
		}
		if((leng[i]>m && tong == 1)){
			tong=0;
			mark1[i]=2;
		}
		if(i>=3){
			if((leng[i-2]+leng[i-1]<=m) && (leng[i-1]+leng[i]<=m) && (leng[i-1]+leng[i-2]+leng[i]>m)){
				mark3[i-2]=1;
				mark4[i+1]=1;
			}
		}
		lst=tmp;
	}//YuChuLi
	if(tong == 1)mark1[n]=2;
	debug1();
	
	long long cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	//cnt1:Left
	//cnt2:Right
	//cnt3:3
	tong=0;
	int flag1=0,flag2=0,flag3=0;
	//flag1: 1XXX3
	//flag2:Zheng Zai Te Shu Suo 
	//		At the SPECIAL area
	//flag3: 4XXX2
	for(int i=1;i<=n;i++){
		if(mark1[i]==1){
			flag1=1;
		}
		if(mark3[i]==1){
			if(flag3==1){
				ans+=(cnt1+1)*(cnt2);
				cnt1=cnt2-1;//?
			}
			if(flag2==1){
				ans+=cnt1+1;
				cnt1=0;
			}
			flag2=1;
			flag1=0;
			cnt3++;
		}
		if(mark4[i]==1){
			cnt3--;
			if(cnt3==0){
				flag2=0;
				flag3=1;
			}
		}
		if(mark1[i]==2){
			if(flag3==1)ans+=(cnt1+1)*(cnt2+1);
			
			if(debugmode==true)cout<<"plus"<<(cnt1+1)*(cnt2+1)<<"and now"<<ans<<endl;
			flag3=0;
			
		}
		
		if(flag1==1){
			cnt1++;
		}
		if(flag3==1){
			cnt2++;
		}
		
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	for(int i=0;i<t;i++){
		init();
	}
	return 0;
}