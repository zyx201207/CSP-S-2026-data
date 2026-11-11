#include<bits/stdc++.h>
using namespace std;
#define LL long long

struct AC{
	LL a;
	LL l;
	LL r;
	char c;
	LL lr=0;
	
};

LL n,neo,ans;
long double mid;

vector<AC> v;

int main(){
	freopen("string.in","r",stdin);//@@@@@@@@@@@@@@@@@@
	freopen("string.out","w",stdout);//@@@@@@@@@@@@@@@@@@@@2
	
	cin>>n;
	
	v.resize(n+5);
	LL ipa;
	char ipc;
	neo=0;
	for(LL i=1;i<=n;i++){
		cin>>ipa>>ipc;
		v[i].a=ipa;
		v[i].l=neo+1;
		v[i].r=neo+ipa;
		neo+=ipa;
		v[i].c=ipc;
	}
	
	LL fy=0,zy=0;
	mid=((long double)neo+(long double)1.0)/((long double)2.0);
///	cout<<"mid"<<mid<<endl;////////////
	for(LL i=1;i<=n;i++){
		if(v[i].l<mid && v[i].r<mid){
			v[i].lr=-1;
			fy++;
		}
		else{
			if(v[i].l>mid && v[i].r>mid){
				v[i].lr=1;
				zy++;
			}
		}
	}
	
	LL fzy=fy+zy;
	bool pf=0;
	if(fzy==n){
		pf=1;
	}
		
		
		
		
		
		
		
		
		
		
		
		
	
	LL lp=1,rp=n,las=0,ras=0;
	char lcs,rcs;
	
	
///	for(LL i=1;i<=n;i++){
///		cout<<"i a c l r lr "<<i<<" "<<v[i].a<<" "<<v[i].c<<" "<<v[i].l<<" "<<v[i].r<<" "<<v[i].lr<<endl;//////////
///	}
	
	LL e;
	
	for(;;){
		if(pf==1){
			e=v[rp].l-v[lp].r;
			if(e==1){
				if(v[lp].c!=v[rp].c){
					ans+=v[lp].a;
				}
				cout<<ans;
				fclose(stdin);//@@@@@@@@@@@@@@@@@@@@@
				fclose(stdout);//@@@@@@@@@@@@@@@@@@@@@@@
				return 0;
			}
		}
		
				
				
				
				
				
				
///		if(v[lp].lr>=0) cout<<"lp!!"<<endl;/////////////
///		if(v[rp].lr<=0) cout<<"rp!!"<<endl;////////////
		if(v[lp].lr>=0 || v[rp].lr<=0){
			las=v[lp].a;
			lcs=v[lp].c;
			ras=v[rp].a;
			rcs=v[rp].c;
			break;
		}
		if(v[lp].a>v[rp].a){
///			cout<<"zd"<<endl;//////////
			if(v[lp].c!=v[rp].c){
				ans+=v[rp].a;
			}
			v[lp].a-=v[rp].a;
			rp--;
	///		cout<<"--la-ra"<<v[lp].a<<v[rp].a<<endl;///////////
			
	///		/////
///			cout<<endl;
///			for(LL i=1;i<=n;i++){
///				cout<<v[i].a<<" "<<v[i].c<<endl;
///			}
///			/////
			continue;
		}
		if(v[lp].a==v[rp].a){
///			cout<<"dy"<<endl;//////////
			if(v[lp].c!=v[rp].c){
				ans+=v[lp].a;
			}
			lp++;
			rp--;
	///		/////
	///		cout<<endl;
	///		for(LL i=1;i<=n;i++){
	///			cout<<v[i].a<<" "<<v[i].c<<endl;
	///		}
	///		/////
			continue;
		}
		if(v[lp].a<v[rp].a){
	///		cout<<"yd"<<endl;//////////
			if(v[lp].c!=v[rp].c){
				ans+=v[lp].a;
			}
			v[rp].a-=v[lp].a;
			lp++;
			
///			/////
///			cout<<endl;
///			for(LL i=1;i<=n;i++){
///				cout<<v[i].a<<" "<<v[i].c<<endl;
///			}
		///	/////
			continue;
		}
		
		
	}
		
	///cout<<"las ras lcs rcs "<<las<<" "<<ras<<" "<<lcs<<" "<<rcs<<endl;//////////
	///cout<<"lp rp"<<lp<<" "<<rp<<endl;///////////
	if(las==ras){
	///	cout<<"dengyu";////
		if(lcs!=rcs){
			ans+=las;
		}
	}
	else{
		if(las>ras){
	///		cout<<"zuoda";////
			if(lcs!=rcs){
				ans+=ras;
			}
		}
		else{
			if(las<ras){
	///			cout<<"youda";////
				if(lcs!=rcs){
					ans+=las;
				}
			}
		}
	}
			
	
	
	cout<<ans;
	
	
	
	
	
	
	
	
	
	
	
	
	
	fclose(stdin);//@@@@@@@@@@@@@@@@@@@@@
	fclose(stdout);//@@@@@@@@@@@@@@@@@@@@@@@
	return 0;
}






















