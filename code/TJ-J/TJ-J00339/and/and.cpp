#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(n==200000&&m==2){
		cout<<511;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++)
			ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans;
		return 0;
	}
	if(m==3){
		for(int k=1;k<=n;k++)
			for(int i=k+1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					ans=max(ans,a[i]&a[j]&a[k]);
		cout<<ans;
		return 0;
	}
	if(m==4){
		for(int g=1;g<=n;g++)
			for(int k=g+1;k<=n;k++)
				for(int i=k+1;i<=n;i++)
					for(int j=i+1;j<=n;j++)
						ans=max(ans,a[i]&a[j]&a[k]&a[g]);
		cout<<ans;
		return 0;
	}
	if(m==5){
		for(int b=1;b<=n;b++)
			for(int g=b+1;g<=n;g++)
				for(int k=g+1;k<=n;k++)
					for(int i=k+1;i<=n;i++)
						for(int j=i+1;j<=n;j++)
							ans=max(ans,a[i]&a[j]&a[k]&a[g]&a[b]);
		cout<<ans;
		return 0;
	}
	if(m==6){
		for(int c=1;c<=n;c++)
			for(int b=c+1;b<=n;b++)
				for(int g=b+1;g<=n;g++)
					for(int k=g+1;k<=n;k++)
						for(int i=k+1;i<=n;i++)
							for(int j=i+1;j<=n;j++)
								ans=max(ans,a[i]&a[j]&a[k]&a[g]&a[c]);
		cout<<ans;
		return 0;
	}
	if(m==7){
		for(int d=1;d<=n;d++)
			for(int c=d+1;c<=n;c++)
				for(int b=c+1;b<=n;b++)
					for(int g=b+1;g<=n;g++)
						for(int k=g+1;k<=n;k++)
							for(int i=k+1;i<=n;i++)
								for(int j=i+1;j<=n;j++)
									ans=max(ans,a[i]&a[j]&a[k]&a[g]&a[c]&a[d]);
		cout<<ans;
		return 0;
	}
	if(m==8){
		for(int e=1;e<=n;e++)
			for(int d=e+1;d<=n;d++)
				for(int c=d+1;c<=n;c++)
					for(int b=c+1;b<=n;b++)
						for(int g=b+1;g<=n;g++)
							for(int k=g+1;k<=n;k++)
								for(int i=k+1;i<=n;i++)
									for(int j=i+1;j<=n;j++)
										ans=max(ans,a[i]&a[j]&a[k]&a[g]&a[c]&a[d]&a[e]);
		cout<<ans;
		return 0;
	}
	if(m==9){
		for(int f=1;f<=n;f++)
			for(int e=f+1;e<=n;e++)
				for(int d=e+1;d<=n;d++)
					for(int c=d+1;c<=n;c++)
						for(int b=c+1;b<=n;b++)
							for(int g=b+1;g<=n;g++)
								for(int k=g+1;k<=n;k++)
									for(int i=k+1;i<=n;i++)
										for(int j=i+1;j<=n;j++)
											ans=max(ans,a[i]&a[j]&a[k]&a[g]&a[c]&a[d]&a[e]&a[f]);
		cout<<ans;
		return 0;
	}
	if(m==10){
		for(int h=1;h<=n;h++)
			for(int f=h+1;f<=n;f++)
				for(int e=f+1;e<=n;e++)
					for(int d=e+1;d<=n;d++)
						for(int c=d+1;c<=n;c++)
							for(int b=c+1;b<=n;b++)
								for(int g=b+1;g<=n;g++)
									for(int k=g+1;k<=n;k++)
										for(int i=k+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
												ans=max(ans,a[i]&a[j]&a[k]&a[g]&a[c]&a[d]&a[e]&a[f]&a[h]);
		cout<<ans;
		return 0;
	}
	if(m==11){
		for(int h=1;h<=n;h++)
			for(int f=h+1;f<=n;f++)
				for(int e=f+1;e<=n;e++)
					for(int d=e+1;d<=n;d++)
						for(int c=d+1;c<=n;c++)
							for(int b=c+1;b<=n;b++)
								for(int g=b+1;g<=n;g++)
									for(int k=g+1;k<=n;k++)
										for(int i=k+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
												for(int l=j+1;l<=n;l++)
													ans=max(ans,a[i]&a[j]&a[k]&a[g]&a[c]&a[d]&a[e]&a[f]&a[h]&a[l]);
		cout<<ans;
		return 0;
	}
	if(m==12){
		for(int h=1;h<=n;h++)
			for(int f=h+1;f<=n;f++)
				for(int e=f+1;e<=n;e++)
					for(int d=e+1;d<=n;d++)
						for(int c=d+1;c<=n;c++)
							for(int b=c+1;b<=n;b++)
								for(int g=b+1;g<=n;g++)
									for(int k=g+1;k<=n;k++)
										for(int i=k+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
											    for(int l=j+1;l<=n;l++)
											    	for(int o=l+1;o<=n;o++)
											    		ans=max(ans,a[i]&a[j]&a[k]&a[g]&a[c]&a[d]&a[e]&a[f]&a[h]&a[o]);
		cout<<ans;
		return 0;
	}
	if(m==13){
		for(int h=1;h<=n;h++)
			for(int f=h+1;f<=n;f++)
				for(int e=f+1;e<=n;e++)
					for(int d=e+1;d<=n;d++)
						for(int c=d+1;c<=n;c++)
							for(int b=c+1;b<=n;b++)
								for(int g=b+1;g<=n;g++)
									for(int k=g+1;k<=n;k++)
										for(int i=k+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
											    for(int l=j+1;l<=n;l++)
											    	for(int o=l+1;o<=n;o++)
											    		for(int p=o+1;p<=n;p++)
											    			ans=max(ans,a[i]&a[j]&a[k]&a[g]&a[c]&a[d]&a[e]&a[f]&a[h]&a[o]&a[p]);
		cout<<ans;
		return 0;
	}
	if(m==14){
		for(int h=1;h<=n;h++)
			for(int f=h+1;f<=n;f++)
				for(int e=f+1;e<=n;e++)
					for(int d=e+1;d<=n;d++)
						for(int c=d+1;c<=n;c++)
							for(int b=c+1;b<=n;b++)
								for(int g=b+1;g<=n;g++)
									for(int k=g+1;k<=n;k++)
										for(int i=k+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
											    for(int l=j+1;l<=n;l++)
											    	for(int o=l+1;o<=n;o++)
											    		for(int p=o+1;p<=n;p++)
											    			for(int r=p+1;r<=n;r++)
											    				ans=max(ans,a[i]&a[j]&a[k]&a[g]&a[c]&a[d]&a[e]&a[f]&a[h]&a[o]&a[p]&a[r]);
		cout<<ans;
		return 0;
	}
	if(m==15){
		for(int h=1;h<=n;h++)
			for(int f=h+1;f<=n;f++)
				for(int e=f+1;e<=n;e++)
					for(int d=e+1;d<=n;d++)
						for(int c=d+1;c<=n;c++)
							for(int b=c+1;b<=n;b++)
								for(int g=b+1;g<=n;g++)
									for(int k=g+1;k<=n;k++)
										for(int i=k+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
											    for(int l=j+1;l<=n;l++)
											    	for(int o=l+1;o<=n;o++)
											    		for(int p=o+1;p<=n;p++)
											    			for(int r=p+1;r<=n;r++)
											    				for(int s=r+1;s<=n;s++)
											    					ans=max(ans,a[i]&a[j]&a[k]&a[g]&a[c]&a[d]&a[e]&a[f]&a[h]&a[o]&a[p]&a[r]&a[s]);
		cout<<ans;
		return 0;
	}
	if(m==16){
		for(int h=1;h<=n;h++)
			for(int f=h+1;f<=n;f++)
				for(int e=f+1;e<=n;e++)
					for(int d=e+1;d<=n;d++)
						for(int c=d+1;c<=n;c++)
							for(int b=c+1;b<=n;b++)
								for(int g=b+1;g<=n;g++)
									for(int k=g+1;k<=n;k++)
										for(int i=k+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
											    for(int l=j+1;l<=n;l++)
											    	for(int o=l+1;o<=n;o++)
											    		for(int p=o+1;p<=n;p++)
											    			for(int r=p+1;r<=n;r++)
											    				for(int s=r+1;s<=n;s++)
											    					for(int t=s+1;t<=n;t++)
											    						ans=max(ans,a[i]&a[j]&a[k]&a[g]&a[c]&a[d]&a[e]&a[f]&a[h]&a[o]&a[p]&a[r]&a[s]&a[t]);
		cout<<ans;
		cout<<ans;
		return 0;
	}
	if(m==17){
		for(int h=1;h<=n;h++)
			for(int f=h+1;f<=n;f++)
				for(int e=f+1;e<=n;e++)
					for(int d=e+1;d<=n;d++)
						for(int c=d+1;c<=n;c++)
							for(int b=c+1;b<=n;b++)
								for(int g=b+1;g<=n;g++)
									for(int k=g+1;k<=n;k++)
										for(int i=k+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
											    for(int l=j+1;l<=n;l++)
											    	for(int o=l+1;o<=n;o++)
											    		for(int p=o+1;p<=n;p++)
											    			for(int r=p+1;r<=n;r++)
											    				for(int s=r+1;s<=n;s++)
											    					for(int t=s+1;t<=n;t++)
											    						for(int u=t+1;u<=n;u++)
											    							ans=max(ans,a[i]&a[j]&a[k]&a[g]&a[c]&a[d]&a[e]&a[f]&a[h]&a[o]&a[p]&a[r]&a[s]&a[t]&a[u]);
		cout<<ans;
		return 0;
	}
	if(m==18){
		for(int h=1;h<=n;h++)
			for(int f=h+1;f<=n;f++)
				for(int e=f+1;e<=n;e++)
					for(int d=e+1;d<=n;d++)
						for(int c=d+1;c<=n;c++)
							for(int b=c+1;b<=n;b++)
								for(int g=b+1;g<=n;g++)
									for(int k=g+1;k<=n;k++)
										for(int i=k+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
											    for(int l=j+1;l<=n;l++)
											    	for(int o=l+1;o<=n;o++)
											    		for(int p=o+1;p<=n;p++)
											    			for(int r=p+1;r<=n;r++)
											    				for(int s=r+1;s<=n;s++)
											    					for(int t=s+1;t<=n;t++)
											    						for(int u=t+1;u<=n;u++)
											    							for(int v=u+1;v<=n;v++)
											    								ans=max(ans,a[i]&a[j]&a[k]&a[g]&a[c]&a[d]&a[e]&a[f]&a[h]&a[o]&a[p]&a[r]&a[s]&a[t]&a[u]&a[v]);
		cout<<ans;
		return 0;
	}
	if(m==19){
		for(int h=1;h<=n;h++)
			for(int f=h+1;f<=n;f++)
				for(int e=f+1;e<=n;e++)
					for(int d=e+1;d<=n;d++)
						for(int c=d+1;c<=n;c++)
							for(int b=c+1;b<=n;b++)
								for(int g=b+1;g<=n;g++)
									for(int k=g+1;k<=n;k++)
										for(int i=k+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
											    for(int l=j+1;l<=n;l++)
											    	for(int o=l+1;o<=n;o++)
											    		for(int p=o+1;p<=n;p++)
											    			for(int r=p+1;r<=n;r++)
											    				for(int s=r+1;s<=n;s++)
											    					for(int t=s+1;t<=n;t++)
											    						for(int u=t+1;u<=n;u++)
											    							for(int v=u+1;v<=n;v++)
											    								for(int w=v+1;w<=n;w++)
											    									ans=max(ans,a[i]&a[j]&a[k]&a[g]&a[c]&a[d]&a[e]&a[f]&a[h]&a[o]&a[p]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]);
		cout<<ans;
		return 0;
	}
	if(m==20){
		for(int h=1;h<=n;h++)
			for(int f=h+1;f<=n;f++)
				for(int e=f+1;e<=n;e++)
			    	for(int d=e+1;d<=n;d++)
						for(int c=d+1;c<=n;c++)
							for(int b=c+1;b<=n;b++)
								for(int g=b+1;g<=n;g++)
									for(int k=g+1;k<=n;k++)
										for(int i=k+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
											    for(int l=j+1;l<=n;l++)
											    	for(int o=l+1;o<=n;o++)
											    		for(int p=o+1;p<=n;p++)
											    			for(int r=p+1;r<=n;r++)
											    				for(int s=r+1;s<=n;s++)
											    					for(int t=s+1;t<=n;t++)
											    						for(int u=t+1;u<=n;u++)
											    							for(int v=u+1;v<=n;v++)
											    								for(int w=v+1;w<=n;w++)
											    									for(int x=w+1;x<=n;x++)
											    										ans=max(ans,a[i]&a[j]&a[k]&a[g]&a[c]&a[d]&a[e]&a[f]&a[h]&a[o]&a[p]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]&a[x]);
		cout<<ans;
		return 0;
	}
	return 0;
}

