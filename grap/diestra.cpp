        #include<bits/stdc++.h>
        using namespace std;
        int n,m;
        map<int,vector<pair<int,int> > > g;
        #define inf 1e18
        long long node[100010],dis[100010];
        priority_queue <int> s;
        void printpath(int n){
            if(n!=1)
                printpath(node[n]);
            printf("%d ",n);
        }
        int main(){
        	cin>>n>>m;
        	int u,v,w;
        	while(m--){
                cin>>u>>v>>w;
        		g[u].push_back({v,w}),g[v].push_back({u,w});
        	}
        	s.push(1);
        	for(int i=1;i<=n;i++)
        		dis[i] = inf,node[i] = i;
        	dis[1] = 0;
        	while(!s.empty()){
        		u = s.top(),s.pop();
               cout<<u<<" ";
        		for(int i=0;i<g[u].size();i++){
        			v = g[u][i].first,w = g[u][i].second;
        			if(dis[u] + w < dis[v]){
        				dis[v] = dis[u] + w,s.push(v);
        				cout<<v<<" ";
        				node[v] = u;
        			}
                }
                 cout<<endl;
        	}
        	if(dis[n]==inf) printf("-1\n");
         	else printpath(n);
        }
