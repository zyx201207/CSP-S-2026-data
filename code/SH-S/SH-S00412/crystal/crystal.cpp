#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//system("fc  crystal3.out crystal3.ans");
	//crystal rp++
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m,ans=1;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	bool dengcha=true;
	ll ooo=a[1]-a[0];
	for(ll i=1;i<n-1;i++){
		if(a[i+1]-a[i]!=ooo){
			dengcha=false;
			break;
		}
	}
	if(dengcha){
		if(ooo==0){
			cout<<n<<"\n";
			return 0;
		}
		ll ppp;
		if(n%2==0){
			ppp=n/2;
		}else{
			ppp=n/2+1;
		}
		for(ll i=1;i<=ppp;i++){
			m-=i*ooo;
			if(m>=0){
				ans++;
			}else{
				cout<<ans<<"\n";
				return 0;
			}
			m-=i*ooo;
			if(m>=0){
				ans++;
			}else{
				cout<<ans<<"\n";
				return 0;
			}
		}
	}
	
	for(ll i=0;i<n;i++){
		ll z=i,y=i,cnt=1,sh=m,zcha,ycha;
		//cout<<"___________________"<<"\n";
		bool zz=true;
	    bool zy=true;
	    bool zyong=true;
	    bool yyong=true;
		//cout<<"找平均值="<<a[i]<<"时的答案"<<"\n"; 
		while(sh>0){
			if(z<=0){
				zz=false;
			}
			if(y>=n-1){
				zy=false;
			}
			if(zz && zyong){
			    z--;
			    zcha=a[i]-a[z];
			    if(zcha>sh){
			    	zz=false;
				}
				zyong=false;
				//cout<<"往左一位与当前值的差："<<zcha<<"\n"; 
			}/*else{
				zz=false;
			}*/
			
			
			if(zy && yyong){
			    y++;
				ycha=a[y]-a[i];	
				if(ycha>sh){
					zy=false;
				}
				yyong=false;
				//cout<<"往右一位与当前值的差："<<ycha<<"\n";
			}/*else{
				zy=false;
			}*/
			
			
			if(!zz && !zy){
				break;
			}
			
			if((zz && zy && zcha>ycha)||(!zz && zy)){
				//zz=false;
				
				sh-=ycha;
				if(sh>=0){
				   cnt++;
				   yyong=true;
				   //cout<<"确认右边，现cnt="<<cnt<<"\n"; 
				}
				else{
				    break;
				}
			}else if(zcha==ycha && zz && zy && zyong && yyong){
				sh=sh-zcha-ycha;
				if(sh>=0){
					cnt+=2;
					yyong=true;
					zyong=true;
					//cout<<"确认两边，现cnt="<<cnt<<"\n"; 
				}
				else{
				    break;
				}
			}else if((zz && zy && zcha<ycha)||(zz && !zy)){
				//zy=false;
				sh-=zcha;
				if(sh>=0){
				   cnt++; 
				   zyong=true;
				   //cout<<"确认左边，现cnt="<<cnt<<"\n"; 
				}
			}
			
			if(cnt>ans){
			    ans=cnt;
				//cout<<"当前第"<<i<<"位（值为"<<a[i]<<"）的答案是："<<cnt<<"\n";
				//cout<<"当前ans="<<ans<<"\n";
				//cout<<"\n";
			}
			 
		}
		
	}
	cout<<ans<<"\n";
	return 0;
}
