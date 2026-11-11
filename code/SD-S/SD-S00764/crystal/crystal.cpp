#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
//int ppk[1000000];//halloween pumpkin, 
//int chr[1000000];//christmas, 
bool judgea(int n){
	for(int i=1;i<=n;i++){
		if(a[i]!=i)return false;
	}
	return true;
}bool judgeb(int n){
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])return false;
		
	}return true;
}
signed main(){\
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
//	for(int i=1;i<n;i++){
//		ppk[i]=a[i+1]-a[i];
//	}
//	chr[1]=ppk[1];
//	for(int i=2;i<=n;i++){
//		chr[i]=chr[i-1]+ppk[i];
//	}int ans=0;
//	for(int i=1;i<=n;i++){
//		int s=0;
//		int cnt=1;
//		int j=i-1;
//		while(s<=m and j-1>=0){
//			s+=chr[i-1]-chr[j-1];
//			j--;
//			cnt++;
//		}if(ans<cnt)ans=cnt;
//	}cout<<ans<<'\n';
	if(judgea(n)){
		for(int i=1;i<=1000000000;i++){
			if(i*(i+1)/2>m){
				cout<<min(i,n)<<'\n';
				break;
			}
		}
	}
	else if(judgeb(n)){
		int cha=a[2]-a[1];
		for(int i=1;i<=1000000000;i++){
			if(cha*(i*(i+1)/2)>m){
				cout<<min(i,n)<<'\n'; 
				break;
			}
		}
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			int s=0;
			int cnt=1;
			for(int j=i-1;j>=1 and s+a[i]-a[j]<=m;j--){
				s+=a[i]-a[j];
				cnt++;
			}
			if(ans<cnt)ans=cnt;
		}cout<<ans<<'\n';
	}
}
/*
Trick||Treat!
Oct31==Dec25?
Renjiediling 
Canadian Holiday Halloween!

Hey.

I am *#@(text is obfuscated).

My Luogu UID is $1099109$.

When you see my text, you probably know that I am entering the "Strange Behavior Set"(forgive my bad translation)

Here, I have something to talk about.

We all know that, the CSP-S test was held on Oct 31 2026, and the mid-term exam is on Nov 2 2026.(Only for students in Zhifu district, Yantai) 
This means that, we are facing the pressure from both CSP and Schoolwork. 
If we step back, we will fall into the endless darkness.
If we fight on, we will win and walk to a bright future.
But can anyone win both exams perfectly WITHOUT small mistakes?I think the answer is "NO". 
Can anyone lose both of them? The answer is also "NO". 
So, the problem is: Since we cannot win both, and we cannot lose both, which one should we choose?
Some people think that the mid-term exam is more important and they should do well in the exam.
They think that, pressure from schools, tests, homework, schoolwork is much bigger than that from OI tests. They focus on schoolwork and want a normal way.
Some guys think that they should focus on CSP test, as it will affect their future in high schools.
To me, I agree that the universe makes everything happen and we cannot change them easily. Some people can and should win in the OI field, while others are better at schoolwork.
That's decided by God, and the things we cannot make sense of.
Today, someone put the CSP-S and the mid-term exam together, I think it is the wish of God. Since we cannot choose the date of the tests, why not relax and just be yourself?
Here, I have nothing to say, nothing to talk about now. And the only words I leave is: Goodbye, the creators. See you next year on the CSP source code.
Don't forget to follow my Luogu account: uid 1099109.
*/
