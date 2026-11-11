#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx=0,minn=1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1 ; i<=n ; i++){
	    cin>>a[i];
	    minn=min(minn,a[i]);
	}
	if(m==1){
		for(int i=1 ; i<=n ; i++) maxx=max(a[i],maxx);
		cout<<maxx;
	}else if(m==n){
		if(minn==0) cout<<0;
		else{
			string s;
			int k=a[1];
            while(k!=0){
			    char s1=(k%2)+'0';
		        s+=s1;
		        k/=2;
		    }
		    reverse(s.begin(),s.end());
		    s+="000000000000000000000000000000";
		    int l=s.size(),k2=0;
		    for(int i=2 ; i<=n ; i++){
			    string s2;
			    k2=a[i];
			    while(k2!=0){
			        char s1=(k2%2)+'0';
		            s2+=s1;
		            k2/=2;
		        }
		        reverse(s2.begin(),s2.end());
		        int l2=s2.size();
		        for(int i=0 ; i<l ; i++){
		        	if(s2[i]=='1' && s[i]=='1') s[i]='1';
		        	else s[i]='0';
				}
				for(int i=0 ; i<l ; i++) if(s[i]=='1') k2=1;
				if(k2==0){
					cout<<0;
					return 0;
				}
		    }
		    int ans=0;
		    for(int i=0 ; i<l ; i++){
		    	if(s[i]=='1'){
		    		ans+=pow(2,i);
				}
			}
			cout<<ans;
		}
	}else if(m==2){
		int k=0,ans=0;
		string s;
		for(int i=1 ; i<=n ; i++){
			k=a[i];
			while(k!=0){
			    char s1=(k%2)+'0';
		        s+=s1;
		        k/=2;
		    }
		    int l=s.size();
			for(int j=i+1 ; j<=n ; j++){
				string s2,s3;
				k=a[j];
			    while(k!=0){
			        char s1=(k%2)+'0';
		            s2+=s1;
		            k/=2;
		        }
		        int l2=s2.size();
		        for(int j=0 ; j<min(l,l2) ; j++){
		        	if(s[j]=='1' && s2[j]=='1') s3+='1';
		        	else s3+='0';
				}
				int p=0,l3=s3.size();
		        for(int j=0 ; j<l3 ; j++){
		    	    if(s3[j]=='1'){
		    		    p+=pow(2,j);
			        }
			    }
			    ans=max(ans,p);
			}
		}
		cout<<ans;
	}
	return 0;
}
