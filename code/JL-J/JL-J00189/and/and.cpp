#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int maxi=0;
	cin>>a[1];
	int h=a[1];
	for(int i=2;i<=n;i++){
        cin>>a[i];
        maxi=max(maxi,a[i]);
        h&=a[i];
	}
	if(m==1){
        cout<<maxi;
        return 0;
	}
	if(m==n){
        cout<<h;
        return h;
	}
	if(m==2){
        int maxi=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    continue;
                }
                maxi=max(maxi,(a[i]&a[j]));
            }
        }
        cout<<maxi;
        return 0;
	}
	if(n<=20){
        int maxi=0;
        if(m==1){
            for(int i=1;i<=n;i++){
                maxi=max(maxi,a[i]);
            }
        }else if(m==2){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    maxi=max(maxi,(a[i]&a[j]));
        }else if(m==3){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        maxi=max(maxi,(a[i]&a[j]&a[k]));
        }else if(m==4){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            maxi=max(maxi,(a[i]&a[j]&a[k]&a[l]));
        }else if(m==5){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                                maxi=max(maxi,(a[i]&a[j]&a[k]&a[l]&a[o]));
        }
        else if(m==5){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                                maxi=max(maxi,(a[i]&a[j]&a[k]&a[l]&a[o]));
        }
        else if(m==6){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                            	for(int p=o+1;p<=n;p++)
                                	maxi=max(maxi,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]));
        }
        else if(m==7){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                            	for(int p=o+1;p<=n;p++)
                            		for(int q=p+1;q<=n;q++)
                                		maxi=max(maxi,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]));
        }
        else if(m==8){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                            	for(int p=o+1;p<=n;p++)
                            		for(int q=p+1;q<=n;q++)
                            			for(int r=q+1;r<=n;r++)
                                			maxi=max(maxi,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]));
        }
        else if(m==9){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                            	for(int p=o+1;p<=n;p++)
                            		for(int q=p+1;q<=n;q++)
                            			for(int r=q+1;r<=n;r++)
                            				for(int s=r+1;s<=n;s++)
                                				maxi=max(maxi,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]));
        }
        else if(m==10){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                            	for(int p=o+1;p<=n;p++)
                            		for(int q=p+1;q<=n;q++)
                            			for(int r=q+1;r<=n;r++)
                            				for(int s=r+1;s<=n;s++)
                            					for(int t=s+1;t<=n;t++)
                                					maxi=max(maxi,(a[t]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]));
        }
        else if(m==11){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                            	for(int p=o+1;p<=n;p++)
                            		for(int q=p+1;q<=n;q++)
                            			for(int r=q+1;r<=n;r++)
                            				for(int s=r+1;s<=n;s++)
                            					for(int t=s+1;t<=n;t++)
                            						for(int u=t+1;u<=n;u++)
                                						maxi=max(maxi,(a[u]&a[t]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]));
        }
        else if(m==12){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                            	for(int p=o+1;p<=n;p++)
                            		for(int q=p+1;q<=n;q++)
                            			for(int r=q+1;r<=n;r++)
                            				for(int s=r+1;s<=n;s++)
                            					for(int t=s+1;t<=n;t++)
                            						for(int u=t+1;u<=n;u++)
                            							for(int v=u+1;v<=n;v++)
                                							maxi=max(maxi,(a[v]&a[u]&a[t]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]));
        }
        else if(m==13){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                            	for(int p=o+1;p<=n;p++)
                            		for(int q=p+1;q<=n;q++)
                            			for(int r=q+1;r<=n;r++)
                            				for(int s=r+1;s<=n;s++)
                            					for(int t=s+1;t<=n;t++)
                            						for(int u=t+1;u<=n;u++)
                            							for(int v=u+1;v<=n;v++)
                            								for(int w=v+1;w<=n;w++)
                                								maxi=max(maxi,(a[w]&a[v]&a[u]&a[t]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]));
        }
        else if(m==14){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                            	for(int p=o+1;p<=n;p++)
                            		for(int q=p+1;q<=n;q++)
                            			for(int r=q+1;r<=n;r++)
                            				for(int s=r+1;s<=n;s++)
                            					for(int t=s+1;t<=n;t++)
                            						for(int u=t+1;u<=n;u++)
                            							for(int v=u+1;v<=n;v++)
                            								for(int w=v+1;w<=n;w++)
                            									for(int x=w+1;x<=n;x++)
                                									maxi=max(maxi,(a[x]&a[w]&a[v]&a[u]&a[t]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]));
        }
        else if(m==15){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                            	for(int p=o+1;p<=n;p++)
                            		for(int q=p+1;q<=n;q++)
                            			for(int r=q+1;r<=n;r++)
                            				for(int s=r+1;s<=n;s++)
                            					for(int t=s+1;t<=n;t++)
                            						for(int u=t+1;u<=n;u++)
                            							for(int v=u+1;v<=n;v++)
                            								for(int w=v+1;w<=n;w++)
                            									for(int x=w+1;x<=n;x++)
                            										for(int y=x+1;y<=n;y++)
                                										maxi=max(maxi,(a[y]&a[x]&a[w]&a[v]&a[u]&a[t]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]));
        }
        else if(m==16){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                            	for(int p=o+1;p<=n;p++)
                            		for(int q=p+1;q<=n;q++)
                            			for(int r=q+1;r<=n;r++)
                            				for(int s=r+1;s<=n;s++)
                            					for(int t=s+1;t<=n;t++)
                            						for(int u=t+1;u<=n;u++)
                            							for(int v=u+1;v<=n;v++)
                            								for(int w=v+1;w<=n;w++)
                            									for(int x=w+1;x<=n;x++)
                            										for(int y=x+1;y<=n;y++)
                            											for(int z=y+1;z<=n;z++)
                                											maxi=max(maxi,(a[z]&a[y]&a[x]&a[w]&a[v]&a[u]&a[t]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]));
        }
        else if(m==17){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                            	for(int p=o+1;p<=n;p++)
                            		for(int q=p+1;q<=n;q++)
                            			for(int r=q+1;r<=n;r++)
                            				for(int s=r+1;s<=n;s++)
                            					for(int t=s+1;t<=n;t++)
                            						for(int u=t+1;u<=n;u++)
                            							for(int v=u+1;v<=n;v++)
                            								for(int w=v+1;w<=n;w++)
                            									for(int x=w+1;x<=n;x++)
                            										for(int y=x+1;y<=n;y++)
                            											for(int z=y+1;z<=n;z++)
                            												for(int e=z+1;e<=n;e++)
                                												maxi=max(maxi,(a[e]&a[z]&a[y]&a[x]&a[w]&a[v]&a[u]&a[t]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]));
        }
        else if(m==18){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                            	for(int p=o+1;p<=n;p++)
                            		for(int q=p+1;q<=n;q++)
                            			for(int r=q+1;r<=n;r++)
                            				for(int s=r+1;s<=n;s++)
                            					for(int t=s+1;t<=n;t++)
                            						for(int u=t+1;u<=n;u++)
                            							for(int v=u+1;v<=n;v++)
                            								for(int w=v+1;w<=n;w++)
                            									for(int x=w+1;x<=n;x++)
                            										for(int y=x+1;y<=n;y++)
                            											for(int z=y+1;z<=n;z++)
                            												for(int e=z+1;e<=n;e++)
                            													for(int f=e+1;f<=n;f++)
                                													maxi=max(maxi,(a[f]&a[e]&a[z]&a[y]&a[x]&a[w]&a[v]&a[u]&a[t]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]));
        }
        else if(m==18){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                            	for(int p=o+1;p<=n;p++)
                            		for(int q=p+1;q<=n;q++)
                            			for(int r=q+1;r<=n;r++)
                            				for(int s=r+1;s<=n;s++)
                            					for(int t=s+1;t<=n;t++)
                            						for(int u=t+1;u<=n;u++)
                            							for(int v=u+1;v<=n;v++)
                            								for(int w=v+1;w<=n;w++)
                            									for(int x=w+1;x<=n;x++)
                            										for(int y=x+1;y<=n;y++)
                            											for(int z=y+1;z<=n;z++)
                            												for(int e=z+1;e<=n;e++)
                            													for(int f=e+1;f<=n;f++)
                            														for(int g=f+1;g<=n;g++)
                                														maxi=max(maxi,(a[g]&a[f]&a[e]&a[z]&a[y]&a[x]&a[w]&a[v]&a[u]&a[t]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]));
        }
        else if(m==19){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                            	for(int p=o+1;p<=n;p++)
                            		for(int q=p+1;q<=n;q++)
                            			for(int r=q+1;r<=n;r++)
                            				for(int s=r+1;s<=n;s++)
                            					for(int t=s+1;t<=n;t++)
                            						for(int u=t+1;u<=n;u++)
                            							for(int v=u+1;v<=n;v++)
                            								for(int w=v+1;w<=n;w++)
                            									for(int x=w+1;x<=n;x++)
                            										for(int y=x+1;y<=n;y++)
                            											for(int z=y+1;z<=n;z++)
                            												for(int e=z+1;e<=n;e++)
                            													for(int f=e+1;f<=n;f++)
                            														for(int g=f+1;g<=n;g++)
                            															for(int c=g+1;c<=n;c++)
                                															maxi=max(maxi,(a[c]&a[g]&a[f]&a[e]&a[z]&a[y]&a[x]&a[w]&a[v]&a[u]&a[t]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]));
        }
        else if(m==20){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++)
                        for(int l=k+1;l<=n;l++)
                            for(int o=l+1;o<=n;o++)
                            	for(int p=o+1;p<=n;p++)
                            		for(int q=p+1;q<=n;q++)
                            			for(int r=q+1;r<=n;r++)
                            				for(int s=r+1;s<=n;s++)
                            					for(int t=s+1;t<=n;t++)
                            						for(int u=t+1;u<=n;u++)
                            							for(int v=u+1;v<=n;v++)
                            								for(int w=v+1;w<=n;w++)
                            									for(int x=w+1;x<=n;x++)
                            										for(int y=x+1;y<=n;y++)
                            											for(int z=y+1;z<=n;z++)
                            												for(int e=z+1;e<=n;e++)
                            													for(int f=e+1;f<=n;f++)
                            														for(int g=f+1;g<=n;g++)
                            															for(int c=g+1;c<=n;c++)
                            																for(int d=c+1;d<=n;d++)
                                																maxi=max(maxi,(a[d]&a[c]&a[g]&a[f]&a[e]&a[z]&a[y]&a[x]&a[w]&a[v]&a[u]&a[t]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]));
        }
        cout<<maxi;
        return 0;
	}
	return 0;
}
