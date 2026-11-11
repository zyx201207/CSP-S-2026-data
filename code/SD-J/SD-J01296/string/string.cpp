#include<iostream>
using namespace std;
char b[1000000],using1,using2;
long long a[1000000],n,l,r,len,ans,used1,used2,ulen1,ulen2,uslen1,uslen2,temp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
		len+=a[i];
	}
	//used1/used2-->用了左/右边区间个数（下次取哪一个） 
	//ulen1/ulen2-->左/右已用长度（接近中间取几个）
	//using1/using2 uslen1/uslen2 
	while(1){
		//cout<<used1<<" "<<used2<<" "<<ulen1<<" "<<ulen2<<" "<<using1<<" "<<using2<<" "<<uslen1<<" "<<uslen2<<"\n";
		if(uslen1==0){
			using1=b[used1];
			uslen1=min(a[used1],len/2-ulen1);//全拿走/快到中点 
			ulen1+=uslen1;
			used1++;
		}
		if(uslen2==0){
			using2=b[n-1-used2];
			uslen2=min(a[n-1-used2],len/2-ulen2);
			ulen2+=uslen2;
			used2++;
		}
		//cout<<"1已经使用个数"<<used1<<" 2已经使用个数"<<used2<<" 1已经使用长度"<<ulen1<<" 2已经使用长度"<<ulen2<<" 1使用中字母"<<using1<<" 2使用中字母"<<using2<<" 1使用中长度"<<uslen1<<" 2使用中长度"<<uslen2<<" "<<ans<<"\n";
		if(using1!=using2){
			temp=min(uslen1,uslen2);
			uslen1-=temp;
			uslen2-=temp;
			ans+=temp;
		}else{
			temp=min(uslen1,uslen2);
			uslen1-=temp;
			uslen2-=temp;
		}
		if(ulen1==len/2&&ulen2==len/2){
			break;
		}
	}
	cout<<ans;
	return 0;
} 
