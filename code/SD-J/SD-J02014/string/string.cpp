//10:30 调出石山 
//10:46 过所有大样例
//时间吃紧 

#include<bits/stdc++.h>
using namespace std;

#define int long long

pair<int,string> a[200005];
pair<int,string> b[200005];

int cnt=0;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n;
	cin>>n;
	
	int sum=0; 
	
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		
		sum += a[i].first;
	}
	
	for(int i=1;i<=n;i++){
		if(a[i].second==b[cnt].second){
			b[cnt].first += a[i].first;
		}
		else{
			b[++cnt].first = a[i].first;
			b[cnt].second = a[i].second;
		}
	}
	
//	cout<<"\n\n\n\n\ncnt"<<cnt<<"\n\n\n\n\n";
	
//	for(int i=1;i<=cnt;i++){
//		cout<<b[i].first<<" "<<b[i].second<<"\n";
//	} 
	
//	cout<<sum<<"\n\n\n\n\n";
	
	if(cnt==1){
		cout<<"0\n";
		
		return 0;
	}
	
	int nsum=0;
	int mid;
	int rmid;
	
	for(int i=1;i<=cnt;i++){
		nsum += b[i].first;
		
		if(nsum>sum/2){
//			cout<<"case 1\n";
			
			if(sum%2&&b[i].first%2){
				cnt += 2;
				
				for(int j=cnt;j>=i+1;j--){
					b[j+2] = b[j];
				}
				
				int t=b[i].first;
				int x=nsum-sum;
				
				i++;
				
				b[i+1].first = x;
				b[i].first = 1;
				b[i-1].first = t-x-1;
				
				mid = i;
				rmid = i+2;
				
				break;
			}
			
			cnt++;
			
			for(int j=cnt;j>=i+1;j--){
				b[j+1] = b[j];
			}
			
			int t=b[i].first;
			
			b[i+1].first = nsum-sum;
			b[i].first = t-b[i+1].first;
			
			mid = i;
			rmid = i+1;
			
			break;
		}
		else if(nsum==sum/2){
//			cout<<"case2"<<"\n";
			
			mid = i;
			rmid = i+1;
			
			break;
		}
	}
	
//	for(int i=1;i<=cnt;i++){
//		cout<<b[i].first<<"CCFNB"<<b[i].second<<"\n";
//	} 
	
	int ans=0;
	int rpos=cnt;
	int lsum=0,rsum=0;
	
	int i=1;
	
//	cout<<"\n--------------"<<mid<<"midmidmid\n"<<rmid<<"rmidrmid?\n";
	
	while(i<=mid&&rpos>=rmid){
		if(b[i].second!=b[rpos].second){
			if(b[i].first<=b[rpos].first){
				b[rpos].first -= b[i].first;
				
				ans += b[i++].first;
			}
			else{
				ans += b[rpos].first;
				
				b[i].first -= b[rpos].first;
				b[rpos].first = 0;
				
				rpos--;
			}
		}
		else{
			if(b[i].first<=b[rpos].first){
				b[rpos].first -= b[i++].first;
				
//				ans += a[i].first;
			}
			else{
//				ans += b[rpos].first;
				
				b[i].first -= b[rpos--].first;
//				b[rpos].first = 0;
				
//				rpos++;
			}
		}
	}
	
	cout<<ans<<"\n";
	
	return 0;
}

//CCF今年又出石山 

/*
3
2 a 2 b 1 c
 
2
2 a
3 a

6
1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b

beeek bekkk beekk
67
*/
