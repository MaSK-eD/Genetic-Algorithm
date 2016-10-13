function createfigure(cdata1)
%CREATEFIGURE(CDATA1)
%  CDATA1:  image cdata

%  Auto-generated by MATLAB on 13-Dec-2015 14:21:35

% Create figure
figure1 = figure;
colormap('gray');

% Create axes
axes1 = axes('Parent',figure1,'Layer','top','TickDir','out','CLim',[0 255],...
    'YDir','reverse',...
    'Position',[0.198630132209765 0.249382710088918 0.602739726027397 0.648148148148148],...
    'DataAspectRatio',[1 1 1]);
%% Uncomment the following line to preserve the X-limits of the axes
% xlim(axes1,[0.5 264.5]);
%% Uncomment the following line to preserve the Y-limits of the axes
% ylim(axes1,[0.5 175.5]);
box(axes1,'on');
hold(axes1,'on');
axis off

% Create image
image(cdata1,'Parent',axes1,'CDataMapping','scaled');

