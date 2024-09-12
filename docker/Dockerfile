FROM ubuntu:20.04

ENV TZ=Europe/Bucharest

# Set timezone and install dependencies
RUN set -ex && \
    ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && \
    echo $TZ > /etc/timezone && \
    apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y \
        apt-utils \
        build-essential \
        git \
        mm-common \
        software-properties-common \
        subversion \
        sudo;

# Install Flatpak and Flatpak Builder
RUN set -ex && \
    add-apt-repository ppa:alexlarsson/flatpak -y && \
    apt-get update -y && \
    apt-get install -y \
        flatpak \
        flatpak-builder;

# Install KDE Platform and SDK via Flatpak
RUN set -ex && \
    flatpak remote-add --if-not-exists flathub https://dl.flathub.org/repo/flathub.flatpakrepo && \
    flatpak install -y flathub org.kde.Platform//5.15-22.08 && \
    flatpak install -y flathub org.kde.Sdk//5.15-22.08

# Clone this repository
ARG REPO_LINK=https://github.com/analogdevicesinc/scopy-flatpak
ARG REPO_LOCAL=/home/docker/scopy-flatpak
ARG REPO_BRANCH=Scopy-1.5.0

RUN set -ex && \
    git clone --recurse-submodules "$REPO_LINK" -b "$REPO_BRANCH" "$REPO_LOCAL" 2> /dev/null || \
    (cd "$REPO_LOCAL"; git pull)

#RUN cd /home/docker/scopy-flatpak && make -j4
#RUN rm -rf Scopy.flatpak
# Default to bash shell
CMD ["/bin/bash"]